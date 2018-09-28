/*
Author: CNYALI_LK
LANG: C++
PROG: d.cpp
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
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
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
int h[505],l[505];
int a[505][505];
int main(){
#ifdef cnyali_lk
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	int no=0,n,m;
	while(~scanf("%d%d",&n,&m)){
		printf("Case %d: ",++no);
		for(int i=1;i<=n;++i)h[i]=0;
		for(int i=1;i<=m;++i)l[i]=0;
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
			a[i][j]=read();
			h[i]+=a[i][j];
			l[j]+=a[i][j];
		}
		int mxh=0,mxl=0,mh=0,ml=0,wa,ac=0;
		for(int i=1;i<=n;++i)if(chkmax(mxh,h[i]))mh=i;
		for(int j=1;j<=m;++j)if(chkmax(mxl,l[j]))ml=j;
		wa=mxh+mxl-a[mh][ml];	
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)chkmax(ac,h[i]+l[j]-a[i][j]);
		if(ac!=wa)printf("Strong\n");
		else printf("Weak\n");
	}
	return 0;
}

