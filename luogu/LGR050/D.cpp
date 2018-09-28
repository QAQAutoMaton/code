/*
Author: CNYALI_LK
LANG: C++
PROG: D.cpp
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
ll fac[233333],inv[233333],invf[233333];
ll f[2333][2333];
ll n,m;	
int main(){
#ifdef cnyali_lk
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	n=read();m=read();
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
	for(ll i=2;i<=200000;++i){
		fac[i]=fac[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=invf[i-1]*inv[i]%p;
	}
	ll ans=0;
	for(ll i=1;i<=n/2;++i)ans=(ans+fac[i+i]*invf[i]%p*invf[i]%p*inv[i+1]%p*fac[n]%p*invf[i+i]%p*invf[n-i-i])%p;
	printf("%lld\n",ans);
	return 0;
}

