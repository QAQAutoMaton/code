/*
Author: QAQ-Automaton
LANG: C++
PROG: 4543.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// prll a signed lleger
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
ll beg[100005],to[200005],lst[200005],e,ans,*f[200005],fw[400005],*g[200005],gw[400005],dep[200005],hvy[200005],t;
void add(ll u,ll v){to[++e]=v;lst[e]=beg[u];beg[u]=e;}
void dfs(ll x,ll f){
	hvy[x]=0;
	for(ll i=beg[x];i;i=lst[i])if(to[i]!=f){
		dfs(to[i],x);
		if(chkmax(dep[x],dep[to[i]]+1))hvy[x]=to[i];
	}
}
ll nmx;
void dfs2(ll x,ll fa,ll gt){
	f[x]=fw+(++t);
	g[x]=gw+gt+dep[x];
	chkmax(nmx,gt+dep[x]+dep[x]+1);
	if(hvy[x])dfs2(hvy[x],x,gt);
	for(ll i=beg[x];i;i=lst[i])if(to[i]!=fa && to[i]!=hvy[x]){
		dfs2(to[i],x,nmx);
		for(ll j=0;j<dep[to[i]];++j){
			ans+=g[to[i]][j+1]*f[x][j];
		}
		for(ll j=0;j<=dep[to[i]];++j){
			ans+=f[to[i]][j]*g[x][j+1];
		}
		for(ll j=0;j<dep[to[i]];++j)g[x][j]+=g[to[i]][j+1];
		for(ll j=0;j<=dep[to[i]];++j)
			g[x][j+1]+=f[x][j+1]*f[to[i]][j];
		for(ll j=0;j<=dep[to[i]];++j)
			f[x][j+1]+=f[to[i]][j];
	}
	ans+=g[x][0];
	++f[x][0];
}
int main(){ 
#ifdef QAQAutoMaton 
	freopen("4543.in","r",stdin);
	freopen("4543.out","w",stdout);
#endif
	ll n,u,v;
	read(n);
	for(ll i=1;i<n;++i){
		read(u,v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1,0,0);
	write(ans,'\n');
	return 0;
}

