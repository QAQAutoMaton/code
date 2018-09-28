/*
Author: CNYALI_LK
LANG: C++
PROG: 1273.cpp
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
int n,m;
int siz[3023];
int dp[3023][3023];
int p[3023];
vector<pii> son[3023];
void DP(int x){
	dp[x][0]=0;
	if(x>n-m){dp[x][1]=p[x];siz[x]=1;return;}
	for(auto i:son[x]){
		DP(i.x);	
		for(int k=siz[x];~k;--k)
			for(int j=1;j<=siz[i.x];++j)
				chkmax(dp[x][k+j],dp[x][k]+dp[i.x][j]-i.y);
		siz[x]+=siz[i.x];
	}
}
int main(){
#ifdef cnyali_lk
	freopen("1273.in","r",stdin);
	freopen("1273.out","w",stdout);
#endif
	n=read();m=read();
	int k,u,w;
	for(int i=1;i<=n-m;++i){
		k=read();
		for(;k;--k){
			u=read();w=read();
			son[i].push_back(make_pair(u,w));
		}
	}
	for(int i=n-m+1;i<=n;++i)p[i]=read();
	memset(dp,-0x3f,sizeof(dp));
	DP(1);
	for(int i=m;i&&dp[1][i+1]<0;--i){
		if(dp[1][i]>=0)printf("%d\n",i);
	}
	return 0;
}

