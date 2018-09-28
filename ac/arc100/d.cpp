/*
Author: CNYALI_LK
LANG: C++
PROG: d.cpp
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
ll A[204848],sf[204848],st[204848];
void calc(ll l,ll r,ll &aw,ll &bw){
	ll al=l,ar=r-1,mid;
	while(al<=ar){
		mid=(al+ar)>>1;
		if((sf[mid]-sf[l-1])<(st[mid+1]-st[r+1]))al=mid+1;
		else ar=mid-1;
	}
	mid=al;
	if(abs((sf[mid]-sf[l-1])-(st[mid+1]-st[r+1]))>abs((sf[mid-1]-sf[l-1])-(st[mid]-st[r+1]))){aw=(sf[mid-1]-sf[l-1]);bw=(st[mid]-st[r+1]);}
	else {aw=(sf[mid]-sf[l-1]);bw=(st[mid+1]-st[r+1]);}
}

int main(){
#ifdef cnyali_lk
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	ll n,a,b,c,d,ans=0x3f3f3f3f;
	n=read();
	for(ll i=1;i<=n;++i){A[i]=read();sf[i]=sf[i-1]+A[i];}
	for(ll i=n;i;--i)st[i]=st[i+1]+A[i];
	for(ll i=1;i<n;++i){
		calc(1,i,a,b);
		calc(i+1,n,c,d);
		chkmin(ans,max(max(a,b),max(c,d))-min(min(a,b),min(c,d)));
	}
	printf("%lld\n",ans);
	return 0;
}

