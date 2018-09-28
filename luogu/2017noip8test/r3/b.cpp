/*
Author: CNYALI_LK
LANG: C++
PROG: b.cpp
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
ll a[2047][2047],rj[2047],b[2047][2047];
ll n,m,xmin,xmax;
ll check(ll w){
	rj[0]=m;
	for(ll i=1;i<=n;++i){
		for(rj[i]=0;rj[i]<rj[i-1]&&a[i][rj[i]+1]<=xmin+w;++rj[i]);
		for(ll j=rj[i]+1;j<=m;++j)if(a[i][j]<xmax-w)return 0;
	}
	return 1;
}
void rrotate(){
	for(ll i=1;i<=n;++i)for(ll j=1;j<=m;++j)b[j][n-i+1]=a[i][j];
	swap(n,m);
	for(ll i=1;i<=n;++i)for(ll j=1;j<=m;++j)a[i][j]=b[i][j];
}
int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	n=read();
	m=read();
	xmin=0x3f3f3f3f3f3f3f3f,xmax=0xcccccccccccccccc;
	for(ll i=1;i<=n;++i)for(ll j=1;j<=m;++j){a[i][j]=read();chkmin(xmin,a[i][j]);chkmax(xmax,a[i][j]);}
	ll ans=0x3f3f3f3f3f3f3f3f,l,r,mid;
	for(ll i=0;i<4;++i){
		l=0;
		r=ans-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		ans=r+1;
		rrotate();
	}
	printf("%lld\n",ans);
	
	return 0;
}

