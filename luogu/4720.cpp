/*
Author: CNYALI_LK
LANG: C++
PROG: 4720.cpp
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
ll a[102424],b[102424],c[102424],d[102424];
ll f[1024242];
ll fpm(ll a,ll b,ll p){
	ll c;
	for(c=1;b;b>>=1,a=a*a%p)if(b&1)c=c*a%p;
	return c;
}
void fac(ll n,ll t,ll &x,ll &y){
	x=1;y=0;
	ll p=c[t],pp=a[t];
	while(n){
		x=x*fpm(f[pp],n/pp,pp)%pp*f[n%pp]%pp;
		n/=c[t];
		y+=n;
	}
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
	}
	else{
		exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
}
ll inv(ll a,ll p){
	ll x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}
void C(ll n,ll m,ll t){
	ll xa,ya,xb,yb,xc,yc;
	f[0]=1;	
	for(ll i=1;i<=a[t];++i){f[i]=f[i-1];if(i%c[t])f[i]=f[i]*i%a[t];}
	fac(n,t,xa,ya);
	fac(m,t,xb,yb);
	fac(n-m,t,xc,yc);
	ll xx,yy;
	yy=ya-yb-yc;
	xx=xa*inv(xb*xc%a[t],a[t])%a[t];
	while(yy){
		xx=xx*c[t]%a[t];
		--yy;
	}
	b[t]=xx;
}
ll CRT(ll t,ll mul){
	ll ans=0,iv,is;
	for(ll i=1;i<=t;++i){
		is=mul/a[i];
		iv=inv(is,a[i]);
		ans=(ans+is*iv%mul*b[i])%mul;
	}
	return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("4720.in","r",stdin);
	freopen("4720.out","w",stdout);
#endif
	ll n,m,p,t=0,sp;
	n=read();m=read();sp=p=read();
	for(ll i=2;i<=p;++i){
		if(!(p%i)){
			c[++t]=i;
			a[t]=1;
			d[t]=0;
			while(!(p%i)){
				a[t]*=i;
				++d[t];
				p/=i;
			}
			C(n,m,t);
		}
	}
	printf("%lld\n",CRT(t,sp));
	return 0;
}

