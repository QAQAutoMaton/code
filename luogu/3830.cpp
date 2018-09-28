/*
Author: CNYALI_LK
LANG: C++
PROG: 3830.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
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
double adp[123],dp[123][123];
int main(){
#ifdef cnyali_lk
	freopen("3830.in","r",stdin);
	freopen("3830.out","w",stdout);
#endif
	int n,tp=read();

	n=read();
	if(tp==1){
		adp[1]=0;
		for(int i=2;i<=n;++i){
			adp[i]=adp[i-1]+2./i;
		}
		printf("%lf\n",adp[n]);
	}
	else{
		dp[1][0]=1;
		for(int i=2;i<=n;++i){
			dp[i][0]=1;
			for(int j=1;j<=i;++j){
				for(int k=1;k<i;++k)dp[i][j]+=dp[k][j-1]+dp[i-k][j-1]-dp[k][j-1]*dp[i-k][j-1];
				dp[i][j]/=(i-1);
			}
		}	
		double ans=0;
		for(int i=1;i<=n;++i)ans+=dp[n][i];
		printf("%lf\n",ans);
	}
	return 0;
}

