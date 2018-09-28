/*
Author: CNYALI_LK
LANG: C++
PROG: 628.cpp
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
const ll p=1008691207;
int main(){
	freopen("628.in","r",stdin);
	freopen("628.out","w",stdout);
	ll n;
	n=read();
	ll ans=p-1,fac=1;
	ans=(ans+n-1)%p;
	for(ll i=1;i<n;++i){
		fac=fac*i%p;
		ans=(ans+fac*(n-i-3+p))%p;
	}
	fac=fac*n%p;
	ans=(ans+fac)%p;
	printf("%lld\n",ans);
	return 0;
}

