/*
Author: CNYALI_LK
LANG: C++
PROG: b.cpp
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
typedef bitset<50010> bt;
struct graph{
	bt ans;
	int beg[50505],to[1024242],lst[1024242],e;
	void add(int u,int v){
		to[++e]=v;
		lst[e]=beg[u];
		beg[u]=e;
	}
	void dfs(int u){
		if(ans[u])return;
		ans[u]=1;
		for(int i=beg[u];i;i=lst[i])dfs(to[i]);
	}	
};
graph a[7];
int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int n=read(),k=read(),m=read(),x,y,z;
	for(;m;--m){
		x=read();y=read();z=read();
		a[z].add(x,y);
		a[z+k].add(y,x);
	}
	for(int i=1;i<=k+k;++i)a[i].dfs(1);
	bt ans=a[1].ans;
	for(int i=2;i<=k;++i)ans&=a[i].ans;
	printf("%d ",n-ans.count()+1);
	ans=a[1+k].ans;
	for(int i=2;i<=k;++i)ans&=a[i+k].ans;
	printf("%d\n",ans.count());
	
	return 0;
}

