/*
Author: CNYALI_LK
LANG: C++
PROG: 1651.cpp
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
	int s=0;
	int base=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=1;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	if(base)s=-s;
	return s;
}
const int N=500000,M=N+N;
int f[2][1000005];
int main(){
#ifdef cnyali_lk
	freopen("1651.in","r",stdin);
	freopen("1651.out","w",stdout);
#endif
	int n,x,a,b;
	for(int i=0;i<=M;++i)f[0][i]=-0x3f3f3f3f;
	f[0][N]=0;
	n=read();
	for(int i=1;i<=n;++i){
		x=read();
		a=i&1;
		b=a^1;
		for(int j=0;j<=M;++j){
			f[a][j]=f[b][j];	
			if(j>=x)chkmax(f[a][j],f[b][j-x]+x);
			if(j<=M-x)chkmax(f[a][j],f[b][j+x]);
		}
	}
	printf("%d\n",f[n&1][N]?f[n&1][N]:-1);
	return 0;
}

