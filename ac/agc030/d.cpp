/*
Author: QAQ-Automaton
LANG: C++ PROG: d.cpp
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
ll a[3005],u[3005],v[3005];
ll f[3005][3005],vf[3005][3005];
ll work(ll x,ll q){return u[q]==x?v[q]:v[q]==x?u[q]:x;}
const ll p=1e9+7,half=5e8+4;
int main(){
#ifdef QAQAutoMaton 
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	ll n,q;
	read(n,q);
	for(ll i=1;i<=n;++i)read(a[i]);
	for(ll i=1;i<=q;++i)read(u[i],v[i]);
	for(ll i=1;i<=n;++i)for(ll j=1;j<=n;++j)f[i][j]=i>j;
	ll x=1;
	for(;q;--q){
		x=x*2%p;
		for(ll i=1;i<=n;++i){
			f[u[q]][i]=f[u[q]][i]*half%p;
			f[v[q]][i]=f[v[q]][i]*half%p;
			if(i!=v[q])	f[i][u[q]]=f[i][u[q]]*half%p;
			if(i!=u[q]) f[i][v[q]]=f[i][v[q]]*half%p;
		}
		for(ll i=1;i<=n;++i){
			vf[u[q]][i]=(f[u[q]][i]+f[v[q]][work(i,q)])%p;
			vf[v[q]][i]=(f[v[q]][i]+f[u[q]][work(i,q)])%p;
			vf[i][u[q]]=(f[i][u[q]]+f[work(i,q)][v[q]])%p;
			vf[i][v[q]]=(f[i][v[q]]+f[work(i,q)][u[q]])%p;
		}
		for(ll i=1;i<=n;++i){
			f[u[q]][i]=vf[u[q]][i];
			f[v[q]][i]=vf[v[q]][i];
			f[i][u[q]]=vf[i][u[q]];
			f[i][v[q]]=vf[i][v[q]];
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;++i)for(ll j=1;j<=n;++j)if(a[i]<a[j])ans=(ans+f[i][j]*x)%p;
	write(ans,'\n');
	return 0;
}

