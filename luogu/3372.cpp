/*
Author: CNYALI_LK
LANG: C++
PROG: 3372.cpp
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
template<class T>void write(T a,char end='\n'){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
ll a[102424],b[102424],c[102424],n,m,l,r,t,w;
#define lowbit(x) (x&(-x))
void add1(ll x,ll y){
	for(;x<=n;x+=lowbit(x))b[x]+=y;
}
void add2(ll x,ll y){
	for(;x<=n;x+=lowbit(x))c[x]+=y;
}
ll sum1(ll x){
	ll s=0;
	for(;x;x^=lowbit(x))s+=b[x];
	return s;
}

ll sum2(ll x){
	ll s=0;
	for(;x;x^=lowbit(x))s+=c[x];
	return s;
}
ll Sum(ll x){
	return a[x]+(x+1)*sum1(x)-sum2(x);
}
int main(){
#ifdef cnyali_lk
	freopen("3372.in","r",stdin);
	freopen("3372.out","w",stdout);
#endif
	n=read();m=read();
	for(ll i=1;i<=n;++i)a[i]=read()+a[i-1];
	for(ll i=1;i<=m;++i){
		if(read()==1){
			l=read();r=read();w=read();
			add1(l,w);
			add1(r+1,-w);
			add2(l,w*l);
			add2(r+1,-w*(r+1));
		}
		else{
			l=read();r=read();
			printf("%lld\n",Sum(r)-Sum(l-1));
		}
	}
	return 0;
}

