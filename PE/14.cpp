/*
Author: CNYALI_LK
LANG: C++
PROG: 14.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
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

tr1::unordered_map<ll,ll> f;

ll Go(ll x){
	if(x==1)return 0;
	if(f.count(x))return f[x];
	return f[x]=Go(x&1?3*x+1:x>>1)+1;
}
int main(){
	ll mx=0,w;	
	for(ll i=2;i<=1000000;++i)if(chkmax(mx,Go(i)))w=i;
	printf("%lld\n",w);
	return 0;
}

