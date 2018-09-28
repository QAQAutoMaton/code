/*
Author: CNYALI_LK
LANG: C++
PROG: gift.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int read(){
	int s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
const int p=1000000007;
int a[666666],f[666666],g[666666];
int main(){
#ifdef cnyali_lk
	freopen("gift.in","r",stdin);
	freopen("gift.out","w",stdout);
#endif
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=n;i;--i){
		f[i]=0;
		for(int j=a[i];j;j=(j-1)&a[i])f[i]=(f[i]+g[j])%p;

		ans=(ans+f[i])%p;
		g[a[i]]+=f[i]+1;
	}
	printf("%d\n",ans);
	return 0;
}

