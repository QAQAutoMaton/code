/*
Author: CNYALI_LK
LANG: C++
PROG: g.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
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
char WritellBuffer[1024];
template<class T>void write(T a,char end){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
ll val[1534567],*a=val+505050,h[505050],add[1534567];
ll chk(ll s,ll n,ll r,ll k){
	for(ll i=1;i<=n;++i){
		add[i]=0;
	}
	ll t;
	for(ll i=1;i<=n;++i){
		add[i]+=add[i-1];
		if(h[i]+add[i]<s){
			k-=t=s-add[i]-h[i];
			add[i]+=t;
			add[i+r+r+1]-=t;
			if(k<0)return 0;
		}
	}
	return k>=0;
}
int main(){
#ifdef cnyali_lk
	freopen("g.in","r",stdin);
	freopen("g.out","w",stdout);
#endif
	ll n,r,k;
	n=read();r=read();k=read();
	for(ll i=1;i<=n;++i){
		a[i]=a[i-1]+read();
	}
	for(ll i=1;i<=r;++i)a[i+n]+=a[i+n-1];
	for(ll i=1;i<=n;++i)h[i]=a[i+r]-a[i-r-1];
	ll ll=1,rr=1500000000000000000LL,mid;
//	cout<<rr<<endl;
	while(ll<=rr){
		mid=(ll+rr)>>1;
		if(chk(mid,n,r,k))ll=mid+1;
		else rr=mid-1;
	}
	cout<<ll-1<<endl;
	return 0;
}

