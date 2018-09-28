/*
Author: CNYALI_LK
LANG: C++
PROG: FWT.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
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
const ll N=1234567;
const ll p=998244353;
const ll inv2=499122177;
namespace Or{
	ll a[N],b[N],c[N];
	void FWT(ll *a,ll n){
		for(ll i=1;i<n;i<<=1){
			for(ll j=0;j<n;j+=i+i){
				for(ll k=0;k<i;++k){
					a[j+k+i]=(a[j+k+i]+a[j+k])%p;	
				}
			}
		}	
	}
	void iFWT(ll *a,ll n){
		for(ll i=1;i<n;i<<=1){
			for(ll j=0;j<n;j+=i+i){
				for(ll k=0;k<i;++k){
					a[j+k+i]=(a[j+k+i]-a[j+k]+p)%p;	
				}
			}
		}	
	}
	void calc(ll n){
		FWT(a,n);
		FWT(b,n);
		for(ll i=0;i<n;++i)c[i]=a[i]*b[i]%p;
		iFWT(c,n);
		for(ll i=0;i<n;++i)printf("%lld%c",c[i],i==n-1?'\n':' ');	
	}
}
namespace And{
	ll a[N],b[N],c[N];
	void FWT(ll *a,ll n){
		for(ll i=1;i<n;i<<=1){
			for(ll j=0;j<n;j+=i+i){
				for(ll k=0;k<i;++k){
					a[j+k]=(a[j+k+i]+a[j+k])%p;	
				}
			}
		}	
	}
	void iFWT(ll *a,ll n){
		for(ll i=1;i<n;i<<=1){
			for(ll j=0;j<n;j+=i+i){
				for(ll k=0;k<i;++k){
					a[j+k]=(a[j+k]-a[j+k+i]+p)%p;	
				}
			}
		}	
	}
	void calc(ll n){
		FWT(a,n);
		FWT(b,n);
		for(ll i=0;i<n;++i)c[i]=a[i]*b[i]%p;
		iFWT(c,n);
		for(ll i=0;i<n;++i)printf("%lld%c",c[i],i==n-1?'\n':' ');	
	}
}

namespace Xor{
	ll a[N],b[N],c[N];
	void FWT(ll *a,ll n){
		for(ll i=1;i<n;i<<=1){
			for(ll j=0;j<n;j+=i+i){
				for(ll k=0;k<i;++k){

					ll u=a[j+k],v=a[j+k+i];
					a[j+k+i]=(u-v+p)%p;	
					a[j+k]=(u+v)%p;	
				}
			}
		}	
	}
	void iFWT(ll *a,ll n){
		for(ll i=1;i<n;i<<=1){
			for(ll j=0;j<n;j+=i+i){
				for(ll k=0;k<i;++k){
					ll u=a[j+k],v=a[j+k+i];
					a[j+k+i]=(u-v+p)*inv2%p;	
					a[j+k]=(u+v)*inv2%p;	
				}
			}
		}	
	}
	void calc(ll n){
		FWT(a,n);
		FWT(b,n);
		for(ll i=0;i<n;++i)c[i]=a[i]*b[i]%p;
		iFWT(c,n);
		for(ll i=0;i<n;++i)printf("%lld%c",c[i],i==n-1?'\n':' ');	
	}
}
int main(){
#ifdef cnyali_lk
	freopen("FWT.in","r",stdin);
	freopen("FWT.out","w",stdout);
#endif
	ll n,m;
	n=read();
	m=1<<n;
	for(ll i=0;i<m;++i)Or::a[i]=And::a[i]=Xor::a[i]=read();
	for(ll i=0;i<m;++i)Or::b[i]=And::b[i]=Xor::b[i]=read();
	Or::calc(m);
	And::calc(m);
	Xor::calc(m);
	return 0;
}

