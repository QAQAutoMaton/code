/*
Author: CNYALI_LK
LANG: C++
PROG: 4705.cpp
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
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;} template<class T>T sqr(T a){return a*a;}
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
const ll p=998244353,g=3,ig=332748118;
ll fpm(ll a,ll b){ll c=1;for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;return c;}
ll f[524288],rev[524288],fac[100005],inv[100005],invf[100005],a[262144],b[262144];

void NTT(ll *f,ll n,ll flag){
	for(ll i=1;i<n;++i){
		rev[i]=(rev[i>>1]>>1)|((i&1)*(n>>1));
		if(i<rev[i])swap(f[i],f[rev[i]]);
	}
	for(ll i=1;i<n;i<<=1){
		ll ww=fpm(g,flag*((p-1)/(i+i))+p-1);
		for(ll j=0;j<n;j+=i+i){
			ll w=1,u,v;	
			for(ll k=0;k<i;++k){
				u=f[j+k];v=f[j+k+i]*w%p;
				f[j+k]=(u+v)%p;
				f[j+k+i]=(u-v+p)%p;
				w=w*ww%p;
			}
		}
	}
	if(!~flag){
		ll in=fpm(n,p-2);
		for(ll i=0;i<n;++i)f[i]=f[i]*in%p;
	}
}
/*void NTT(ll *a,ll n,ll flag){
  for(ll i=1;i<n;++i){
  rev[i]=(rev[i>>1]>>1)|((i&1)*(n>>1));
  if(i>rev[i])swap(a[i],a[rev[i]]);
  }
  ll w,ww,u,v;	
  for(ll i=1;i<n;i<<=1){
  w=fpm(flag>0?g:ig,(p-1)/i/2);
  for(ll j=0;j<n;j+=i+i){
  ww=1;
  for(ll k=0;k<i;++k){
  u=a[j+k];v=a[j+k+i]*ww%p;
  a[j+k]=(u+v)%p;
  a[j+k+i]=(u-v+p)%p;
  ww=ww*w%p;
  }
  }
  }
  if(flag<0){
  ll invn=fpm(n,p-2);
  for(ll i=0;i<n;++i)a[i]=a[i]*invn%p;
  }
  }*/
void Inv(ll *a,ll n,ll *b){
	if(n==1){b[0]=fpm(a[0],p-2);b[1]=0;return;}
	Inv(a,n>>1,b);
	for(ll i=0;i<n;++i)f[i]=a[i];
	for(ll i=0;i<n;++i)f[i+n]=0;
	for(ll i=n>>1;i<n<<1;++i)b[i]=0;
	NTT(f,n<<1,1);
	NTT(b,n<<1,1);
	for(ll i=0;i<n<<1;++i)b[i]=(2*b[i]-b[i]*b[i]%p*f[i]%p+p)%p;
	NTT(b,n<<1,-1);
	for(ll i=n;i<n+n;++i)b[i]=0;	
/*	NTT(b,n<<1,1);
	for(ll i=0;i<n+n;++i)f[i]=f[i]*b[i]%p;
	NTT(f,n<<1,-1);
	NTT(b,n<<1,-1);
	printf("%lld:",n);
	for(ll i=0;i<n;++i)printf("%lld%c",b[i],i==n-1?'\n':' ');
	for(ll i=0;i<n;++i)printf("%lld%c",f[i],i==n-1?'\n':' ');
	for(ll i=1;i<n;++i)if(f[i]){printf("%lld???%lld!!!\n",n,i);exit(0);};
	if(f[0]!=1){printf("%lld?%lld~\n",n,f[0]);exit(0);}*/
}
struct Polynomial{
	ll a[524288],b[524288],n;
	void solve(ll k){
		ll N=1;
		for(;N<4*n;N<<=1);
		for(ll i=0;i<N;i+=4)a[i]=1;
		for(ll i=4;i<N;i<<=1)
			for(ll j=0;j<N;j+=i+i){
				NTT(a+j,i,1);
				NTT(a+j+i,i,1);
				for(ll k=0;k<i;++k){
					a[j+k]=a[j+k]*a[j+k+i]%p;
					a[j+k+i]=0;
				}
				NTT(a+j,i,-1);
			}
		//		for(ll i=0;i<=n;++i)printf("%lld%c",a[i],i==n?'\n':' ');
		N>>=2;
		for(;N<=k;N<<=1);
		Inv(a,N,b);
		//		for(ll i=0;i<=n;++i)printf("%lld%c",b[i],i==n?'\n':' ');
		for(ll i=0;i<=n;++i)a[i]=a[i]*(n-i)%p;
		NTT(a,N+N,1);
		NTT(b,N+N,1);
		for(ll i=0;i<N+N;++i)b[i]=b[i]*a[i]%p;
		NTT(b,N+N,-1);
		for(ll i=k+1;i<N+N;++i)b[i]=0;
		//		for(ll i=0;i<=n;++i)printf("%lld%c",b[i],i==n?'\n':' ');
	}
};
Polynomial f1,f2;
int main(){
#ifdef cnyali_lk
	freopen("4705.in","r",stdin);
	freopen("4705.out","w",stdout);
#endif
	ll n,m,k,x;
	read(n,m);
	f1.n=n;f2.n=m;
	for(ll i=0;i<n;++i){read(x);f1.a[i*4+1]=p-x;}
	for(ll i=0;i<m;++i){read(x);f2.a[i*4+1]=p-x;}
	read(k);
	f1.solve(k);
	f2.solve(k);
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
	for(ll i=2;i<=k||i<=n||i<=m;++i){
		fac[i]=fac[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=invf[i-1]*inv[i]%p;
	}
	for(ll i=0;i<=k;++i){
		a[i]=f1.b[i]*invf[i]%p;
		b[i]=f2.b[i]*invf[i]%p;
	}
	ll N=1;
	while(N<=k*2)N<<=1;
	NTT(a,N,1);
	NTT(b,N,1);
	for(ll i=0;i<N;++i)a[i]=a[i]*b[i]%p;
	NTT(a,N,-1);
	for(ll i=1;i<=k;++i)write(a[i]*fac[i]%p*inv[n]%p*inv[m]%p,'\n');
	return 0;
}

