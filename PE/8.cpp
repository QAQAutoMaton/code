/*
Author: CNYALI_LK
LANG: C++
PROG: 8.cpp
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
char s[1023]; 
ll a[1023];
int main(){
#ifdef cnyali_lk
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
#endif
	ll n=1000;
	ll mx=0;
	scanf("%s\n",s+1);
	for(ll i=1;i<=n;++i)a[i]=s[i]-'0';
	for(ll i=1;i<=n;++i)chkmax(mx,a[i]*a[i+1]*a[i+2]*a[i+3]*a[i+4]*a[i+5]*a[i+6]*a[i+7]*a[i+8]*a[i+9]*a[i+10]*a[i+11]*a[i+12]);
	printf("%lld\n",mx);
	return 0;
}

