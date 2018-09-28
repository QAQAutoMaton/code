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
typedef __int128 ll;
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
ll a[1048575],b[1048575];
ll n,m;
ll s[1048575];
void Add(ll x,ll y){
	while(x<=m){
		s[x]+=y;	
		x+=x&(-x);
	}
}
ll Sum(ll x){
	ll sum=0;
	while(x){
		sum+=s[x];
		x^=x&(-x);
	}
	return sum;
}
void write(ll x){
	ll a=0,b=0;
	do{
		a=a*10+(x%10);
		x/=10;
		++b;
	}while(x);
	while(b){
		putchar(a%10+'0');
		--b;
		a/=10;
	}

	
}
int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	n=read();
	for(ll i=n;i;--i){
		a[i]=read();
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(ll i=1;i<=n;++i)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	ll ans=0;
	for(ll i=1;i<=n;++i){
		Add(a[i],i);
		ans+=(n-i+1)*Sum(a[i]-1);
	}
	write(ans);	

	
	return 0;
}

