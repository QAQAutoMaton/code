/*
Author: CNYALI_LK
LANG: C++
PROG: 1315.cpp
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
const ll inf=0x3f3f3f3f;
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
	inline void read (ll &x) {
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
	inline void write (ll x) {
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
ll go[1005],arrive[1005],cnt[1005],tim[1005];
ll w[10005],s[10005],t[10005];
int main(){
#ifdef cnyali_lk
	freopen("1315.in","r",stdin);
	freopen("1315.out","w",stdout);
#endif
	ll n,m,k,ans=0;
	read(n,m,k);
	for(ll i=2;i<=n;++i){
		read(tim[i]);
	}
	for(ll i=1;i<=m;++i){
		read(w[i],s[i],t[i]);
		++cnt[t[i]];
		chkmax(go[s[i]],w[i]);
	}
	for(ll i=1;i<=n;++i){cnt[i]+=cnt[i-1];chkmax(go[i],go[i-1]);arrive[i]=max(arrive[i-1],go[i-1])+tim[i];}
	for(ll i=1;i<=m;++i)ans+=arrive[t[i]]-w[i];
	while(k){

		ll ls=n,c=-1,l,t,w;
		for(ll i=n-1;i;--i){
			if(arrive[i]<=go[i]){
				if(tim[i+1]&&chkmax(c,cnt[ls]-cnt[i])){
					t=ls;l=i+1;
				}	
				ls=i;
			}
		}
		if(!~c)break;
		w=min(tim[l],k);
		for(ll i=l;i<t;++i){
			chkmin(w,arrive[i]-go[i]);	
		}
		tim[l]-=w;
		for(ll i=l;i<t;++i)arrive[i]-=w;
		ans-=w*c;
		k-=w;
	}
	printf("%lld\n",ans);
	return 0;
}

