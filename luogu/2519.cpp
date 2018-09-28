/*
Author: CNYALI_LK
LANG: C++
PROG: 2519.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
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
tr1::unordered_map<ll,int> mp;
vector<pii> lst[102423];
int f[102423];
int main(){
#ifdef cnyali_lk
	freopen("2519.in","r",stdin);
	freopen("2519.out","w",stdout);
#endif
	int n,l,r;
	pii a;
	n=read();
	for(int i=1;i<=n;++i){
		l=read();r=read();	
		r=n-r;
		lst[r].push_back(make_pair(l,++mp[(ll)l*n+r]));
	}
	for(int i=1;i<=n;++i){
		chkmax(f[i],f[i-1]);	
		for(auto j:lst[i])chkmax(f[i],f[j.x]+min(j.y,i-j.x));
	}
	printf("%d\n",n-f[n]);
	return 0;
}

