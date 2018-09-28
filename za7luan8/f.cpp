/*
Author: CNYALI_LK
LANG: C++
PROG: f.cpp
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
ll check(ll x,ll y){
	ll mul=1;
	for(ll i=x;i>1;--i){
		mul=mul*i;
		if(mul>y)return 0;
		if(mul==y)return i-1;
	}
	return 0;
}

int main(){
#ifdef cnyali_lk
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	ll k,no=0;
	while(~scanf("%lld",&k)){
		printf("Case %lld: ",++no);
		if(k==1)printf("Impossible\n");
		else{
			ll fnd=0,s;
			for(ll i=2;i<=100000;++i)if(s=check(i,k)){
				fnd=1;
				printf("%lld %lld\n",i,s);
				break;
			}	
			if(!fnd)printf("%lld %lld\n",k,k-1);
		}
	}
	return 0;
}

