/*
Author: CNYALI_LK
LANG: C++
PROG: 624.cpp
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
ll p,n,w;
ll fpm(ll a,ll b){
	ll c=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
ll _sqrt(ll a){
	for(ll i=0;i<p;++i)if(i*i%p==a)return i;
	return 0;
}
int main(){
#ifdef cnyali_lk
	freopen("624.in","r",stdin);
	freopen("624.out","w",stdout);
#endif
	n=read();p=read();	
	ll sq5=_sqrt(5),i4=fpm(4,p-2);
	ll x=(1+sq5)*i4%p,y=(1-sq5+p)*i4%p;
	ll u=fpm(x,n),v=fpm(y,n);
	printf("%lld\n",(u*fpm((1-u+p)*x%p,p-2)%p-v*fpm((1-v+p)*y%p,p-2)%p+p)*fpm(sq5*2,p-2)%p);
	return 0;
}

