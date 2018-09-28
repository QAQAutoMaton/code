/*
Author: CNYALI_LK
LANG: C++
PROG: a.cpp
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
ll a[1048575],b[1048575];
int main(){
#ifdef cnyali_lk
	freopen("A.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ll n,q,x,y;
	n=read();
	for(ll i=1;i<=n;++i)a[i]=b[i]=read();
	q=read();
	for(;q;--q){
		x=read();y=read();
		for(ll i=1;i<=n;++i)a[i]=b[i];
		for(ll i=1;i<=x;++i){
			a[n+1]=a[1];
			for(ll j=1;j<=n;++j)a[j]=(a[j]+a[j+1])%p;
		}
		printf("%lld\n",a[y]);
	}
	return 0;
}

