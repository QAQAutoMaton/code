/*
Author: CNYALI_LK
LANG: C++
PROG: 4239.cpp
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
	for(;b;b>>=1){
		if(b&1)c=c*a%p;
		a=a*a%p;
	}
	return c;
}

ll f[266661],g[266661],m,inv[266661],af[266661];
void FFT(ll *f,ll n,ll flag){
	for(ll i=1;i<n;++i){
		inv[i]=(inv[i>>1]>>1)|((i&1)*(n>>1));
		if(i<inv[i])swap(f[i],f[inv[i]]);
	}
	for(ll i=1;i<n;i<<=1){
		ll w=fpm(3,((p-1)/i/2)*(flag+p-1)),ww;
		for(ll j=0;j<n;j+=i+i){
			ww=1;
			for(ll k=0;k<i;++k){
				ll u=f[j+k],v=f[j+k+i]*ww%p;
				f[j+k]=(u+v)%p;
				f[j+k+i]=(u-v+p)%p;
				ww=ww*w%p;
			}
		}
	}
	if(flag<0){
		ll in=fpm(n,p-2);
		for(ll i=0;i<n;++i)f[i]=f[i]*in%p;
	}
}
void Inv(ll n){
	if(n==1){
		g[0]=fpm(f[0],p-2);
	}
	else{
		Inv(n>>1);
		FFT(g,n<<1,1);	
		for(int i=0;i<n;++i)af[i]=f[i],af[i+n]=0;
		FFT(af,n<<1,1);
		for(ll i=0;i<n+n;++i)g[i]=(g[i]*2-af[i]*g[i]%p*g[i]%p+p)%p;
		FFT(g,n<<1,-1);
		for(ll i=0;i<n;++i)g[i+n]=0;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("4239.in","r",stdin);
	freopen("4239.out","w",stdout);
#endif
	ll n;m=1;
	n=read();
	for(ll i=0;i<n;++i)f[i]=read();
	for(;m<n;m<<=1);
	Inv(m);
	for(ll i=0;i<n;++i)printf("%lld%c",g[i],i==n-1?'\n':' ');
	return 0;
}

