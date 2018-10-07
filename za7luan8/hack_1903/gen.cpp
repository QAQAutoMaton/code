/*
Author: CNYALI_LK
LANG: C++
PROG: gen.cpp
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
int s;
int l[50005],r[50005];
int beg[50005],lst[50005];
void make(int n){
	int blk=1357;
	beg[0]=1;
	for(int i=1;i<=n;++i)
		if(i/blk != (i-1)/blk){lst[(i-1)/blk]=i-1;beg[i/blk]=i;}
	lst[n/blk]=n;
	int t=n/blk;
	for(int i=0;i<=t;++i){
		l[++s]=beg[i];r[s]=beg[i];
		l[++s]=beg[i];r[s]=beg[i];
		for(int j=i;j<=t;++j){
			l[++s]=beg[i];r[s]=lst[j];
			l[++s]=beg[i];r[s]=lst[j];
		}
	}
	l[++s]=lst[t];r[s]=lst[t];
	l[++s]=lst[t];r[s]=lst[t];
}
int main(){
	freopen("hack.in","w",stdout);
	int n=50000,m=50000;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i)printf("1%c",i==n?'\n':' ');
	make(n);	
	for(int i=1;i<=s;i+=2)printf("Q %d %d\n",l[i],r[i]);
	;
	for(int i=1;i<=m-s;++i)printf("R %d 2\n",i);
	;
	for(int i=2;i<=s;i+=2)printf("Q %d %d\n",l[i],r[i]);
	
	return 0;
}

