/*
Author: CNYALI_LK
LANG: C++
PROG: c.cpp
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
ll fpm(ll a,ll b){
	ll c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
ll f[262333],g[262333],s[262333],fac[102423],inv[102423],invf[102423],h[262333];
const ll N=100001;
namespace poly{
	const ll p=998244353,g=3;
	ll rev[262333],p1[262333];
	ll pf[262333],pg[262333];
	ll fpm(ll a,ll b){
		ll c=1;
		for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
		return c;
	}
	void NTT(ll n,ll *f,ll flag){
		flag=(flag+p-1)%(p-1);
		for(ll i=1;i<n;++i){
			rev[i]=(rev[i>>1]>>1)+(i&1)*(n>>1);
			if(i<rev[i])swap(f[i],f[rev[i]]);
		}
		for(ll i=1;i<n;i<<=1){
			ll w=fpm(g,(p-1)/(i*2)*flag);
			for(ll j=0;j<n;j+=i+i){
				ll ww=1,u,v;	
				for(ll k=0;k<i;++k){
					u=f[j+k];
					v=f[j+k+i]*ww%p;
					f[j+k]=(u+v)%p;
					f[j+k+i]=(u-v+p)%p;
					ww=ww*w%p;
				}
			}
		}
		if(flag==p-2){
			ll in=fpm(n,p-2);
			for(ll i=0;i<n;++i)f[i]=f[i]*in%p;
		}
	}
	void Mul(ll na,ll *f,ll nb,ll *g,ll *h){
		ll n=1;
		while(n<na+nb)n<<=1;
		for(ll i=0;i<n;++i){
			pf[i]=f[i];
			pg[i]=g[i];
			if(i>na)f[i]=0;
			if(i>nb)g[i]=0;
		}
		NTT(n,f,1); 
		if(f!=g)NTT(n,g,1);
		for(ll i=0;i<n;++i)h[i]=f[i]*g[i]%p;
		NTT(n,h,-1);
		if(h!=f){
			for(ll i=0;i<n;++i)f[i]=pf[i];
		}
		if(h!=g){
			for(ll i=0;i<n;++i)g[i]=pg[i];
		}
	}
	void Inv(ll n,ll *f,ll *g){
		if(n==1){
			g[0]=fpm(*f,p-2);
			return;
		}
		Inv((n+1)>>1,f,g);	
		ll fn=1;
		while(fn<n+n)fn<<=1;
//		fn<<=1;
		for(ll i=0;i<fn;++i){
			p1[i]=f[i];
			if(i>=n)f[i]=0;
		}
		NTT(fn,f,1);
		NTT(fn,g,1);
		for(ll i=0;i<fn;++i){
			g[i]=(2*g[i]-f[i]*g[i]%p*g[i]%p+p)%p;
			f[i]=p1[i];
		}
		NTT(fn,g,-1);
		for(ll i=n;i<fn;++i)g[i]=0;
		/*
		for(ll i=0;i<n;++i){
			p1[i]=0;
			for(ll j=0;j<=i;++j)p1[i]=(p1[i]+f[j]*g[i-j])%p;
			printf("%lld%c",p1[i],i==n-1?'\n':' ');
		}
		*/
	}
}
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	ll n,m;
	/*
	n=read();
	for(ll i=0;i<n;++i)f[i]=read();
	poly::Inv(n,f,g);
	poly::Mul(n-1,f,n-1,g,h);
	for(ll i=0;i<n;++i)printf("%lld%c",h[i],i==n+n-2?'\n':' ');*/

	invf[0]=invf[1]=inv[1]=fac[0]=fac[1]=1;
	g[0]=1;
	g[1]=s[1]=0;
	for(ll i=2;i<=N;++i){
		fac[i]=fac[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=inv[i]*invf[i-1]%p;
		g[i]=fpm(i-1,i)*invf[i]%p;
		s[i]=g[i]*i%p;
	}
//	debug("QaQ?\n");
	poly::Inv(N,g,h);
//	poly::Mul(N-1,g,N-1,h,f);
//	for(ll i=0;i<N;++i)assert(f[i]==!i);
		/*debug("%lld%c",f[i],i==N-1?'\n':' ');*/
	poly::Mul(N-1,h,N-1,s,f);
	for(ll i=0;i<N;++i)f[i]=f[i]*fac[i-1]%p;
//	printf("HHH\n");
	ll t,x;	
	t=read();
	for(;t;--t){
		x=read();	
//		printf("%lld\n",f[x]);
		printf("%lld\n",x==1?0:(f[x]-fpm(x,x-2)*(x-1)%p+p)*(p+1>>1)%p);
	}

	return 0;
}

