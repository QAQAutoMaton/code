/*
Author: CNYALI_LK
LANG: C++
PROG: 3317.cpp
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
double a[55][55];
double det(int n){
	double ans=1;
	//for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)printf("%lf%c",a[i][j],j==n?'\n':' ');
	for(int i=1;i<=n;++i){
		int j;
		for(j=i;j<=n&&abs(a[j][i])<eps;++j);
		if(j>n)return 0;
		for(int k=1;k<=n;++k)swap(a[i][k],a[j][k]);
		ans*=a[i][i];
	//	printf("%lf\n",ans);
		for(j=i+1;j<=n;++j){
			double s=a[j][i]/a[i][i];
			for(int k=i;k<=n;++k)a[j][k]-=a[i][k]*s;
		}
	//	for(int x=1;x<=n;++x)for(int y=1;y<=n;++y)printf("%lf%c",a[x][y],y==n?'\n':' ');
	}
	return abs(ans);
}
int main(){
#ifdef cnyali_lk
	freopen("3317.in","r",stdin);
	freopen("3317.out","w",stdout);
#endif
	int n;
	double s=1,pp;
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%lf",&pp);	
			if(pp<eps)pp=eps;
			if(pp>1-eps)pp=1-eps;
			if(i!=j){
				a[i][j]=pp/(1-pp);
				a[i][i]-=pp/(1-pp);
			}
			if(j<i)s=s*(1-pp);
		}
	}
	printf("%lf\n",det(n-1)*s);
	return 0;
}

