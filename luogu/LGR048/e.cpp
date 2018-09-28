/*
Author: CNYALI_LK
LANG: C++ PROG: e.cpp Mail: cnyalilk@vip.qq.com
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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll p=998244353;
ll inv[102];
ll C(ll a,ll b){
	ll ans=1;
	for(ll i=1;i<=b;++i){
		ans=ans*(a-b+i)%p;
	}
	for(ll i=1;i<=b;++i)ans=ans*inv[i]%p;
	return ans;
}
ll n,k,ans;
ll ys[102424],sm;
ll times(ll a,ll b,ll p){
	ll c=0;
	a%=p;
	while(b){
		if(b&1)c=(c+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return c;
}
ll qpow(ll a,ll b,ll p){
	ll c=1;
	a%=p;
	while(b){
		if(b&1)c=times(c,a,p);
		a=times(a,a,p);
		b>>=1;
	}
	return c;
}
ll Miller_Rabin(ll n){
	if(n==2)return 1;
	ll s=n-1,t=0;
	while(!(s%2)){
		s>>=1;
		++t;
	}
	for(ll i=1;i<=128;++i){
		ll a=(((ll)(rand())<<31)|rand())%(n-1)+1,b,c;
		b=qpow(a,s,n);
		for(ll j=1;j<=t;++j){
			c=times(b,b,n);
			if(c==1&&b!=n-1&&b!=1)return 0;
			b=c;
		}
		if(b!=1)return 0;
	}
	return 1;
}
ll f(ll x,ll a,ll p){
	return (times(x,x,p)+a)%p;
}
void Pollard_Rho(ll n){
	if(n==1)return;
	if(Miller_Rabin(n)){
		ys[sm]=n;
		++sm;
		return;
	}
	ll a=0,x,y;
	do{
		++a;
		x=1,y=f(x,a,n);
		while(gcd((y-x+n)%n,n)==1){
			x=f(x,a,n);
			y=f(y,a,n);
			y=f(y,a,n);
//			debug("%lld,%lld\n",x,y);
		}
		if(y!=x){
			Pollard_Rho(gcd((y-x+n)%n,n));
			Pollard_Rho(n/gcd((y-x+n)%n,n));
		}
	}while(y==x);
}
int main(){
#ifdef cnyali_lk
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	srand(123456701);
	inv[1]=1;
	for(ll i=2;i<=80;++i)inv[i]=(p-p/i)*inv[p%i]%p;
	n=read();k=(read()+1)%p;
	if(n==1){printf("1\n");return 0;}
	ans=1;
	ll s=0;
	Pollard_Rho(n);
	sort(ys,ys+sm);
//	for(ll i=0;i<sm;++i)printf("%lld\n",ys[i]);
	for(ll i=0;i<sm;){
		s=0;
		while(ys[i+s]==ys[i])++s;
		i+=s;
		ans=(ans*C((k+s)%p,s))%p;
	}
	printf("%lld\n",ans);
	return 0;
}

