/*
Author: CNYALI_LK
LANG: C++
PROG: 4091.cpp
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
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
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
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
const ll p=998244353;
const ll _g=3;
const ll N=262144;
ll fac[N+15],inv[N+15],invf[N+15];
ll f[N+15],g[N+15],rev[N+15];
ll fpm(ll a,ll b){
	ll c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
void NTT(ll *f,ll flag){
	for(ll i=1;i<N;++i){
		rev[i]=(rev[i>>1]>>1)|((i&1)*(N>>1));
		if(i<rev[i])swap(f[i],f[rev[i]]);
	}
	ll ww,w,u,v;
	for(ll i=1;i<N;i<<=1){

		ww=fpm(_g,(p-1)/(i+i)*(p-1+flag)%(p-1));
		for(ll j=0;j<N;j+=i+i){
			w=1;
			for(ll k=0;k<i;++k){
				u=f[j+k];
				v=f[j+k+i]*w%p;
				f[j+k]=(u+v)%p;
				f[j+k+i]=(u-v+p)%p;
				w=w*ww%p;
			}
		}
	}
	if(flag<0){
		ll in=fpm(N,p-2);
		for(ll i=0;i<N;++i)f[i]=f[i]*in%p;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("4091.in","r",stdin);
	freopen("4091.out","w",stdout);
#endif
	ll n;
	n=read();
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;	
	for(ll i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=inv[i]*invf[i-1]%p;
	}
	f[0]=1;f[1]=p-1;
	g[0]=1;g[1]=n+1;
	for(ll i=2;i<=n;++i){
		f[i]=invf[i];
		if(i&1)f[i]=p-f[i];
		g[i]=(fpm(i,n+1)+p-1)*inv[i-1]%p*invf[i]%p;
	}
	NTT(f,1);
	NTT(g,1);
	for(ll i=0;i<N;++i)f[i]=f[i]*g[i]%p;
	NTT(f,-1);
	ll ans=f[0],s=1;
	for(ll i=1;i<=n;++i){
		s=s*2%p;
		ans=(ans+s*fac[i]%p*f[i])%p;
	}
	printf("%lld\n",ans);
	return 0;
}

