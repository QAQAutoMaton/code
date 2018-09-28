/*
Author: CNYALI_LK
LANG: C++
PROG: test.cpp
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
int n,m,a[2047][2047],b[2047][2047];
void rrotate(){
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)b[j][n-i+1]=a[i][j];
	swap(n,m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=b[i][j];
}

int main(){
#ifdef cnyali_lk
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif
	n=read();m=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=read();
	rrotate();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("%d%c",a[i][j],j==m?'\n':' ');;
	rrotate();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("%d%c",a[i][j],j==m?'\n':' ');;
	rrotate();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("%d%c",a[i][j],j==m?'\n':' ');;
	rrotate();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("%d%c",a[i][j],j==m?'\n':' ');;
	return 0;
}

