/*
Author: CNYALI_LK
LANG: C++
PROG: 1070.cpp
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
int a[1926][1926];
int cst[1926][1926];
int f[1926];
int main(){
#ifdef cnyali_lk
	freopen("1070.in","r",stdin);
	freopen("1070.out","w",stdout);
#endif
	int n,m,p,wa;
	n=read();m=read();p=read();
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)a[((i-j)%n+n)%n][j+1]=read();
	for(int i=0;i<n;++i)for(int j=1;j<=m;++j)a[i][j]+=a[i][j-1];
//	for(int i=0;i<n;++i)for(int j=1;j<=m;++j)printf("%d%c",a[i][j],j==m?'\n':' ');
	for(int i=0;i<n;++i){
		wa=read();
		for(int j=0;j<m;++j)cst[(((i-j)%n)+n)%n][j+1]=wa;
	}
	for(int i=1;i<=m;++i){
		f[i]=-0x3f3f3f3f;
		for(int j=max(1,i-p+1);j<=i;++j){
			for(int k=0;k<n;++k)chkmax(f[i],f[j-1]+a[k][i]-a[k][j-1]-cst[k][j]);
		}
	}
	printf("%d\n",f[m]);
	return 0;
}

