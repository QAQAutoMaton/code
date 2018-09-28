/*
Author: CNYALI_LK
LANG: C++
PROG: b.cpp
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
int f[6002][6002];
int pre[6002],lst[6002];
const int p=1000000007;
int a[6002];
int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int t;
	t=read();
	for(;t;--t){
		int n,m,k;
		n=read();m=read();k=read();
		for(int i=1;i<=k;++i)lst[i]=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			pre[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int i=n;i;--i){
			f[i][i]=1;
			lst[a[i]]=i;
			for(int j=i+1;j<=n;++j){
				f[i][j]=((long long)f[i][j-1]+f[lst[a[j]]+1][j-1]-f[lst[a[j]]+1][pre[j]-1]+(pre[j]<lst[a[j]]&&lst[a[j]]<=j)+(pre[j]<=lst[a[j]]&&lst[a[j]]<j)+p)%p;
			}
		}
		for(int l,r;m;--m){
			l=read();r=read();printf("%d\n",f[l][r]);
		}
	}
	return 0;
}

