/*
Author: CNYALI_LK
LANG: C++
PROG: NTT.cpp
Mail: cnyalilk@vip.qq.com
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
ll s,a[333333],b[333333],c[333333],rev[333333];
const ll p=998244353;
const ll g=3;
ll fpm(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1)c=c*a%p;
		a=a*a%p;
		b>>=1;
	}
	return c;
}

ll invs;
void NTT(ll *a,ll flag){
	for(ll i=0;i<s;++i)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(ll i=1;i<s;i<<=1){
		ll w=fpm(g,((flag+(p-1))*(p-1)/i/2));
		for(ll j=0;j<s;j+=i+i){
			ll aw=1,u,v;
			for(ll k=0;k<i;++k){
				u=a[j+k],v=a[j+k+i]*aw%p;
				a[j+k]=(u+v)%p;
				a[j+k+i]=(u-v+p)%p;
				aw=aw*w%p;
			}
		}
	}
	if(flag<0)for(ll i=0;i<s;++i)a[i]=a[i]*invs%p;
}
int main(){
#ifdef cnyali_lk
	freopen("NTT.in","r",stdin);
	freopen("NTT.out","w",stdout);
#endif
	ll n,m;
	n=read();m=read();
	for(ll i=0;i<=n;++i)a[i]=read();
	for(ll i=0;i<=m;++i)b[i]=read();
	for(s=1;s<=n+m;s<<=1);
	for(ll i=1;i<s;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(s>>1));
	invs=fpm(s,p-2);
	NTT(a,1);
	NTT(b,1);
	for(ll i=0;i<s;++i)c[i]=a[i]*b[i]%p;
	NTT(c,-1);
	for(ll i=0;i<=n+m;++i)printf("%lld%c",c[i],i==n+m?'\n':' ');
	return 0;
}

