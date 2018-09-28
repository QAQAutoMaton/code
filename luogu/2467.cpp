/*
Author: CNYALI_LK
LANG: C++
PROG: 2467.cpp
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
ll up[2][4205],down[2][4205];
int main(){
#ifdef cnyali_lk
	freopen("2467.in","r",stdin);
	freopen("2467.out","w",stdout);
#endif
	ll n,p,bt,ibt;	
	n=read();p=read();
	up[1][1]=down[1][1]=1;
	for(int i=2;i<=n;++i){
		bt=i&1;
		ibt=bt^1;
		for(int j=1;j<=i;++j){
			up[bt][j]=(up[bt][j-1]+down[ibt][j])%p;
		}
		for(int j=i;j;--j){
			down[bt][j]=(down[bt][j+1]+up[ibt][j-1])%p;
		}
	}
	printf("%d\n",(up[bt][n]+down[bt][1])%p);
	return 0;
}

