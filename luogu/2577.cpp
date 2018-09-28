/*
Author: CNYALI_LK
LANG: C++
PROG: 2577.cpp
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
struct person{
	int a,b;
};
person a[255];
int t[255],f[255][65535],vis[255][65535];
int n;
int dfs(int x,int y){
	if(x>n)return 0;
	if(vis[x][y])return f[x][y];
	vis[x][y]=1;
	f[x][y]=min(max(dfs(x+1,y),t[x]-y+a[x].b),max(dfs(x+1,y+a[x].a),a[x].a+y+a[x].b));
	return f[x][y];
}
int main(){
#ifdef cnyali_lk
	freopen("2577.in","r",stdin);
	freopen("2577.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;++i){
		a[i].a=read();a[i].b=read();	
	}
	sort(a+1,a+n+1,[](person a,person b){return a.b>b.b;});
	for(int i=1;i<=n;++i)t[i]=a[i].a+t[i-1];
	printf("%d\n",dfs(1,0));
	return 0;
}

