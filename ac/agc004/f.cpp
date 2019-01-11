/*
Author: QAQ-Automaton
LANG: C++
PROG: f.cpp
Mail: cnyalilk@vip.qq.com */
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
const ll inf=1e12;
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
	inline void read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}

	inline void read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		x=gc();
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
	}
	template<typename A,typename ...B>
	inline void read(A &x,B &...y){
		read(x);read(y...);
	}
	// prll a signed lleger
	inline void write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}

	inline void write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void write (char x) {
		putc(x);
	}
	inline void write(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void write(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
	inline void write(A x,B ...y){
		write(x);write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
ll f[100005][2],tag[100005],OddCircle;
ll cnt[100005];
vector<ll> son[100005],QAQ[100005];
void dfs(ll x,ll flg){
	if(tag[x]){if(tag[x]!=flg)OddCircle=1;return;}
	tag[x]=flg;
	for(auto i:son[x])dfs(i,-flg);
}
ll vis[100005],fa[100005];
void dfs2(ll x,ll fa){
	vis[x]=1;
	cnt[x]=tag[x];
	for(auto i:son[x])if(i!=fa && !vis[i]){
		dfs2(i,x);
		cnt[x]+=cnt[i];
	}
}
namespace Tree{
	void main(ll n){
		dfs2(1,0);
		if(cnt[1]){write("-1\n");return;}
		ll ans=0;
		for(ll i=1;i<=n;++i)ans+=abs(cnt[i]);
		write(ans,'\n');
	}
}
pii E;
void gete(ll x,ll f){
	fa[x]=f;
	vis[x]=1;
	cnt[x]=tag[x];
	for(auto i:son[x])if(i!=f){
		if(!vis[i]){
			gete(i,x);
			cnt[x]+=cnt[i];
		}
		else{
			E=make_pair(x,i);
		}
	}
}
namespace Odd{
	void main(ll n){
		gete(1,0);
		if(cnt[1]%2){write("-1\n");return;}
		tag[E.x]-=cnt[1]>>1;
		tag[E.y]-=cnt[1]>>1;
		ll ans=abs(cnt[1]>>1);
		for(ll i=1;i<=n;++i)vis[i]=0;
		dfs2(1,0);
		for(ll i=1;i<=n;++i)ans+=abs(cnt[i]);
		write(ans,'\n');
	}
}
namespace Even{
	ll a[100005];
	void main(ll n){
		gete(1,0);
		if(cnt[1]){write("-1\n");return;}
		for(ll i=1;i<=n;++i)vis[i]=0;
		ll ans=0,t=0;
		for(ll i=1;i<=n;++i)ans+=abs(cnt[i]);
		ll u=E.x,v=E.y;
		for(;u&&u!=v;u=fa[u]);
		if(u==v)u=E.x;
		else{
			u=E.y;
			v=E.x;
		}
		for(;u!=v;u=fa[u]){
			ans-=abs(cnt[u]);
			a[++t]=cnt[u];
		}
		a[++t]=0;
		sort(a+1,a+t+1);
		ll mid=(t+1)>>1;
		for(ll i=1;i<=t;++i)ans+=abs(a[i]-a[mid]);
		write(ans,'\n');
	}
}
int main(){
#ifdef QAQAutoMaton 
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	ll n,m,u,v;	
	read(n,m);
	for(;m;--m){
		read(u,v);
		son[u].push_back(v);
		son[v].push_back(u);
	}
	dfs(1,1);
	if(n==m+1)Tree::main(n);
	else if(OddCircle)Odd::main(n);
	else Even::main(n);
	return 0;

}

