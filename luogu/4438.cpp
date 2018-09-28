/*
Author: CNYALI_LK
LANG: C++
PROG: 4438.cpp
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
char WritellBuffer[1024];
template<class T>void write(T a,char end){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
ll f[21474][41][41],a[43211],b[43211],c[43211],son[43211][2];
bool vis[21474][41][41];
ll n;
ll func(ll i,ll j,ll k){
	if(i>=n)return c[i]*(a[i]+j)*(b[i]+k);
	if(vis[i][j][k])return f[i][j][k];
	vis[i][j][k]=1;
	return f[i][j][k]=min(func(son[i][0],j+1,k)+func(son[i][1],j,k),func(son[i][0],j,k)+func(son[i][1],j,k+1));
}
int main(){
#ifdef cnyali_lk
	freopen("4438.in","r",stdin);
	freopen("4438.out","w",stdout);
#endif
	n=read();
	for(ll i=1;i<n;++i){
		son[i][0]=read();
		if(son[i][0]<0)son[i][0]=n-1-son[i][0];

		son[i][1]=read();
		if(son[i][1]<0)son[i][1]=n-1-son[i][1];
	}
	for(ll i=n;i<n+n;++i)a[i]=read(),b[i]=read(),c[i]=read();
	printf("%lld\n",func(1,0,0));
	return 0;
}

