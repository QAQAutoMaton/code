/*
Author: CNYALI_LK
LANG: C++
PROG: 4929.cpp
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
int a[505][505],n,m;
int l[505][505],r[505][505],u[505][505],d[505][505];
int begX[505],begY[505],delX[505],delY[505],slt[505];
void Build(){
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(a[i][j]){
		l[i][j]=begX[i];
		r[i][j]=0;
		r[i][begX[i]]=j;
		begX[i]=j;
		u[i][j]=begY[j];
		d[i][j]=0;
		d[begY[j]][j]=i;
		begY[j]=i;
		++cnt[j];
	}
}
int AlgoX(){
	int mns=0x3f3f3f3f,y=0;
	for(int i=1;i<=m;++i)if(!delY[i] && chkmin(mns,cnt[i]))y=i;
	for(int i=begY[]
	return 0;
}
int main(){
#ifdef cnyali_lk
	freopen("4929.in","r",stdin);
	freopen("4929.out","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=read();
	Build();
	if(AlgoX()){for(int i=1;i<=n;++i)if(slt[i])printf("%d ",i);putchar('\n');}
	else printf("No Solution!\n");

	return 0;
}

