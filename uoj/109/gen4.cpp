/*
Author: CNYALI_LK
LANG: C++
PROG: gen4.cpp
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
vector<pii> e[66];
int main(){
	freopen("tasksauthor4.out","w",stdout);
	int n=33,k=-1;	
	for(int i=n-3;i>=0;i-=2){
		e[i].push_back(make_pair(i+1,k));
		e[i].push_back(make_pair(i+2,2*k));
		e[i+1].push_back(make_pair(i+2,2*k));

		k=k*2;
	}
	printf("%d\n",n);
	for(int i=0;i<n;++i){
		printf("%d",e[i].size());
		for(auto x:e[i])printf(" %d %d",x.x,x.y);
		putchar('\n');
	}
	int m=6;
	printf("%d\n",m);
	for(int i=1;i<=m;++i)printf("%d %d\n",0,n-1);
	return 0;
}

