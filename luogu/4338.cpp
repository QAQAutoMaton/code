/*
Author: CNYALI_LK
LANG: C++
PROG: 4338.cpp
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
ll a[400005],fa[400005],son[400005][2],add[400005],hvy[400005],as[400005],ans,w[400005];
ll beg[400005],to[800005],lst[800005],e,lsa[400005];
void ae(ll u,ll v){
	to[++e]=v;lst[e]=beg[u];beg[u]=e;
}
void rotate(ll x){
	ll f=fa[x],ff=fa[f],fx=son[f][1]==x;
	fa[x]=ff;fa[f]=x;
	if(son[ff][0]==f)son[ff][0]=x;
	if(son[ff][1]==f)son[ff][1]=x;
	fa[son[f][fx]=son[x][fx^1]]=f;
	son[x][fx^1]=f;
}
#define ntr(x) (fa[x] && (son[fa[x]][0]==x||son[fa[x]][1]==x))
void push_tag(ll x){
	if(ntr(x))push_tag(fa[x]);
	if(add[x]){
		a[x]+=add[x];
		add[son[x][0]]+=add[x];
		add[son[x][1]]+=add[x];
		add[x]=0;
	}
}
void splay(ll x){
	push_tag(x);
	while(ntr(x)){
		ll f=fa[x];
		if(ntr(f)){
			if((son[f][1]==x)==(son[fa[f]][1]==f))rotate(f);else rotate(x);
		}
		rotate(x);
	}
}
ll query(ll x){
	if(!x)return 0;
	splay(x);
	return a[x];
}
void updheavy(ll x,ll y){
	splay(x);
	son[x][1]=0;
	if(y){
		splay(y);
		son[x][1]=y;
	}
	hvy[x]=y;
}
ll fr(ll x){
	splay(x);
	for(;son[x][0];x=son[x][0]);
	splay(x);
	return x;
}
ll calc(ll x){
	ll ans=min(query(x)-1,2*(query(x)-max(w[x],query(hvy[x]))));
	if(ans<0){
		debug("%d|%d,%d  %d|%d\n",x,query(x),w[x],hvy[x],query(hvy[x]));	
		exit(0);
	}
	return ans;
}

void dfs(ll x,ll f){
	fa[x]=f;
	for(ll i=beg[x];i;i=lst[i])if(to[i]!=f){dfs(to[i],x);a[x]+=a[to[i]];}
	for(ll i=beg[x];i;i=lst[i])if(to[i]!=f && a[x]+1<=2*a[to[i]]){
		son[x][1]=hvy[x]=to[i];	
	}
	ans+=lsa[x]=calc(x);
}
void upd(ll x,ll y){
	int ffaa;
	ans-=lsa[x];
	while(x){
		splay(x);	
		add[son[x][0]]+=y;
		a[x]+=y;
		if(hvy[x] && 2*query(hvy[x])<=a[x])updheavy(x,0);
		ans+=lsa[x]=calc(x);
		x=fr(x);
		ffaa=fa[x];
		if(ffaa){
			ans-=lsa[ffaa];
			if(a[x]*2>=query(ffaa)+1)updheavy(ffaa,x);
		}
		x=ffaa;
	}
} 
int main(){
#ifdef cnyali_lk
	freopen("4338.in","r",stdin);
	freopen("4338.out","w",stdout);
#endif
	ll n,q,x,y;
	read(n,q);
	for(ll i=1;i<=n;++i){read(a[i]);w[i]=a[i];}
	for(ll i=2;i<=n;++i){read(x,y);ae(x,y);ae(y,x);}
	dfs(1,0);
	debug("%lld\n",fa[25412]);
	printf("%lld\n",ans);
	for(;q;--q){
		read(x,y);	
		w[x]+=y;
		upd(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}

