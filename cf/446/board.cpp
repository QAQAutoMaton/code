/*
Author: CNYALI_LK
LANG: C++
PROG: board.cpp
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
const ll p=1000000009;
ll fpm(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1)c=c*a%p;
		a=a*a%p;
		b>>=1;
	}
	return c;
}
const ll sq5=616991993;
const ll inv2=(p+1)>>2;
const ll invsq5=723398404;
const ll A=308495997;
const ll B=691504013;
int main(){
	ll n,sa,sb,inv2=(p+1)>>1,ia,ib,isq;
	printf("%lld\n",fpm(sq5,p-2));
	printf("%lld\n",(1+sq5)*inv2%p);
	printf("%lld\n",(1-sq5+p)*inv2%p);

	return 0;
}

