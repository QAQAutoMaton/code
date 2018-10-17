/*
Author: CNYALI_LK
LANG: C++
PROG: 1975.cpp
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
struct BIT{
	ll n,a[102423];
	void add(ll x,ll y){for(;x<=n;x+=x&-x)a[x]+=y;}
	ll sum(ll x){ll y=0;for(;x;x^=x&-x)y+=a[x];return y;}
}bit;
ll h[102423],A[102423];
int main(){
#ifdef cnyali_lk
	freopen("1975.in","r",stdin);
	freopen("1975.out","w",stdout);
#endif
	ll n,m,t,a,b,ha,hb;
	n=read();
	for(ll i=1;i<=n;++i){A[i]=h[i]=read();}
	m=read();
	sort(A+1,A+n+1);
	t=unique(A+1,A+n+1)-A-1;
	for(ll i=1;i<=n;++i)h[i]=lower_bound(A+1,A+t+1,h[i])-A;
	bit.n=t;
	ll cnt=0;
	for(ll i=n;i;--i){
		cnt+=bit.sum(h[i]-1);
		bit.add(h[i],1);
	}
	printf("%lld\n",cnt);
	for(;m;--m){
		a=read();b=read();	
		if(a>b)swap(a,b);
		ha=h[a];hb=h[b];
		for(ll i=1;i<a;++i)if(h[i]>ha)--cnt;
		for(ll i=a+1;i<=n;++i)if(h[i]<ha)--cnt;
		h[a]=-1;
		for(ll i=1;i<b;++i)if(h[i]>hb)--cnt;
		for(ll i=b+1;i<=n;++i)if(h[i]<hb)--cnt;
		h[b]=ha;
		for(ll i=1;i<b;++i)if(h[i]>ha)++cnt;
		for(ll i=b+1;i<=n;++i)if(h[i]<ha)++cnt;
		h[a]=hb;
		for(ll i=1;i<a;++i)if(h[i]>hb)++cnt;
		for(ll i=a+1;i<=n;++i)if(h[i]<hb)++cnt;
		printf("%lld\n",cnt);
	}
	return 0;
}

