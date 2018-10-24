/*
Author: CNYALI_LK
LANG: C++
PROG: b.cpp
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
ll Log(ll n,ll k){
	ll t=0;
	while(n/=k)++t;
	return t;
}
ll orz(ll n,ll x){
	ll l=2,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(Log(n,mid)>=x)l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
ll f[1000005],p[1000005],pri[1000005],ps,w[101];
tr1::unordered_map<ll,ll> ff;
ll N=1000000;
void init_mu(){
	f[1]=0;
	for(ll i=2;i<=N;++i){
		if(!f[i])for(ll j=i*i;j<=N;j*=i)f[j]=1;
		f[i]=1-f[i]+f[i-1];
	}
}
ll F(ll n){
	if(n<=N)return f[n];
	if(ff.count(n))return ff[n];
	ll s=n-1,c=Log(n,2),m;
	for(ll i=c;i>1;--i){
		s-=F(orz(n,i));
	}
	return ff[n]=s;
}

int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	init_mu();
	ll n,c;
	n=read();
	printf("%lld\n",n-F(n));
	
	return 0;
}

