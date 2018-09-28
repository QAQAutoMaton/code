/*
Author: CNYALI_LK
LANG: C++
PROG: 4718.cpp
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
ll mul(ll a,ll b,ll p){
	ll c=0;
	for(;b;b>>=1,a=(a+a)%p)if(b&1)c=(c+a)%p;
	return c;
}
ll fpm(ll a,ll b,ll p){
	ll c=1;
	for(;b;b>>=1,a=mul(a,a,p))if(b&1)c=mul(c,a,p);
	return c;
}
ll Miller_Rabin(ll n){
	if(n==1)return 0;
	if(n==2)return 1;
	if(!(n&1))return 0;
	ll s=n-1,t=0,x,a,b;
	for(;!(s&1);s>>=1,++t);
	for(ll i=1;i<=30;++i){
		x=(((ll)rand())<<31|rand())%(n-1)+1;
		a=fpm(x,s,n);
		for(ll j=1;j<=t;++j){
			b=mul(a,a,n);
			if(b==1&&!(a==1||a==n-1))return 0;
			a=b;
		}
		if(b!=1)return 0;
	}
	return 1;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll f(ll x,ll c,ll n){
	return (mul(x,x,n)+c)%n;
}
ll Pollard_Rho(ll n){
	if(n==1)return 0;
	if(Miller_Rabin(n))return n;
	ll x=1,y=1;
	for(ll c=1;x==y;++c){
		x=rand()%n;
		y=f(x,c,n);
		while(gcd((x-y+n)%n,n)==1){
			x=f(x,c,n);
			y=f(y,c,n);
			y=f(y,c,n);
		}
	}
	x=gcd((x-y+n)%n,n);
	return max(Pollard_Rho(x),Pollard_Rho(n/x));
	
}
int main(){
#ifdef cnyali_lk
	freopen("4718.in","r",stdin);
	freopen("4718.out","w",stdout);
#endif
	ll t,n;
    srand(time(0));
	t=read();
	for(;t;--t){
		n=read();
		if(n==1)printf("Fuck Problem-Maker\n");
		else if(Miller_Rabin(n))printf("Prime\n");
		else printf("%lld\n",Pollard_Rho(n));
	}
	return 0;
}

