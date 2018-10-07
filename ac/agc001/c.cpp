/*
Author: CNYALI_LK
LANG: C++
PROG: c.cpp
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
int n,k,s;
int beg[2005],to[4005],lst[4005],e,cnt[2005];
void add(int u,int v){to[++e]=v;lst[e]=beg[u];beg[u]=e;}
int dfs(int x,int fa,int dep){
	if(dep>s){cnt[x]=1;return 0;}
	int tot=1;
	cnt[x]=0;
	for(int i=beg[x];i;i=lst[i])if(to[i]!=fa){
		tot+=dfs(to[i],x,dep+1);
		cnt[x]+=cnt[to[i]];
	}
	return tot;
}
int calc(int x){
	int s=dfs(x,0,0),g=0;
	if(k)for(int i=beg[x];i;i=lst[i])chkmax(g,cnt[to[i]]);
	return s+g;
}
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	n=read();
	k=read();
	int u,v;
	s=k>>1;
	k=k&1;
	for(int i=1;i<n;++i){
		u=read();v=read();
		add(u,v);
		add(v,u);
	}	
	int ans=0;
	for(int i=1;i<=n;++i)chkmax(ans,calc(i));
	printf("%d\n",n-ans);
	return 0;
}

