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
vector<pii> e[355];
int main(){
	freopen("tasksauthor5.out","w",stdout);
	//954 edges with w>0
	int n=300;
	printf("%d\n",n);
	for(int i=n-1;i;--i)e[i].push_back(make_pair(i-1,-1));	
	for(int i=1;i<=40;++i)e[0].push_back(make_pair(rand()%n,rand()%1000000));
	for(int i=0;i<n;++i){
		printf("%d",e[i].size());
		for(auto x:e[i])printf(" %d %d",x.first,x.second);
		putchar('\n');
	}
	printf("%d\n",10);
	for(int i=0;i<10;++i)printf("%d %d\n",n-1,0);
	return 0;
}

