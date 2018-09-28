/*
Author: CNYALI_LK
LANG: C++
PROG: a.cpp
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
const ll p=19260817;
ll dis[204847],fdis[204847],tdis[204847];
ll w[204847],fw[204847],tw[204847],qw[204847];
int main(){
#ifdef cnyali_lk
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ll n,m,x,l,r;
	n=read();
	m=read();
	for(ll i=1;i<n;++i)dis[i]=read()%p;
	for(ll i=1;i<=n;++i){
		w[i]=read()%p;
		qw[i]=(qw[i-1]+w[i])%p;
	}
	for(ll i=2;i<=n;++i){
		fdis[i]=(dis[i-1]+fdis[i-1])%p;
		fw[i]=(fw[i-1]+fdis[i]*w[i])%p;
	}
	for(ll i=n-1;i;--i){
		tdis[i]=(tdis[i+1]+dis[i])%p;
		tw[i]=(tw[i+1]+tdis[i]*w[i])%p;
	}
	for(;m;--m){
		x=read();l=read();r=read();	
		if(x<l){
			printf("%lld\n",(fw[r]-fw[l-1]+p-fdis[x]*(qw[r]-qw[l-1]+p)%p+p)%p);
		}
		else if(r<x){
			printf("%lld\n",(tw[l]-tw[r+1]+p-tdis[x]*(qw[r]-qw[l-1]+p)%p+p)%p);
		}
		else{
			printf("%lld\n",((fw[r]-fw[x]+p-fdis[x]*(qw[r]-qw[x])%p+p)+(tw[l]-tw[x]+p-tdis[x]*(qw[x-1]-qw[l-1])%p+p))%p);
		}
	}
	return 0;
}

