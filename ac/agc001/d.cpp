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
	int s=0;
	int base=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=1;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	if(base)s=-s;
	return s;
}
int a[102423];
int main(){
#ifdef cnyali_lk
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	int n,m,cntO=0;
	n=read();m=read();
	for(int i=1;i<=m;++i)a[i]=read(),cntO+=a[i]&1;
	if(cntO>2)printf("Impossible\n");
	else{
		for(int i=2;i<m;++i)
			if(a[i]&1)if(a[1]&1){swap(a[i],a[m]);--i;}
			else swap(a[i],a[1]);
		for(int i=1;i<=m;++i)printf("%d%c",a[i],i==m?'\n':' ');
		if(m==1)a[++m]=a[1],a[1]=0;
		++a[1];
		if(!--a[m])--m;
		
		printf("%d\n",m);
		for(int i=1;i<=m;++i)printf("%d%c",a[i],i==m?'\n':' ');
	}
	return 0;
}

