/*
Author: CNYALI_LK
LANG: C++
PROG: e.cpp
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
	ll s=0;
	ll base=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=1;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	if(base)s=-s;
	return s;
}
ll x[200005],y[200005];
ll f[4005][4005],fac[8005],inv[8005],invf[8005];
const ll p=1000000007,t=2001;
int main(){
#ifdef cnyali_lk
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	ll n;
	fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
	for(ll i=2;i<=t*4;++i){
		fac[i]=fac[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p;
		invf[i]=invf[i-1]*inv[i]%p;
	}
	n=read();
	for(ll i=1;i<=n;++i){
		x[i]=read();y[i]=read();
		++f[t-x[i]][t-y[i]];
	}
	for(ll i=1;i<=t*2;++i)for(ll j=1;j<=t*2;++j)f[i][j]=(f[i][j]+f[i-1][j]+f[i][j-1])%p;
	ll cnt=0;
	for(ll i=1;i<=n;++i)cnt=(cnt+f[t+x[i]][t+y[i]]-fac[x[i]*2+y[i]*2]*invf[x[i]*2]%p*invf[y[i]*2]%p+p)%p;
	printf("%lld\n",cnt*((p+1)>>1)%p);
	return 0;
}

