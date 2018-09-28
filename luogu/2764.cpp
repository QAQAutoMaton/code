/*
Author: CNYALI_LK
LANG: C++
PROG: 2764.cpp
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
int a[155][155],tx[155],ty[155],vis[155],n,m;
int dfs(int x){
	if(!x)return 1;
	if(vis[x])return 0;
	vis[x]=1;
	for(int i=1;i<=n;++i)if(a[x][i]){
		if(dfs(ty[i])){
			ty[i]=x;
			tx[x]=i;
			return 1;
		}
	}
	return 0;
}
void go(int x){
	while(x){
		printf("%d%c",x,tx[x]?' ':'\n');
		x=tx[x];
	}
}

int main(){
#ifdef cnyali_lk
	freopen("2764.in","r",stdin);
	freopen("2764.out","w",stdout);
#endif
	int x,y;	
	n=read();m=read();
	for(int i=1;i<=m;++i){
		x=read();y=read();
		a[x][y]=1;		
	}
	int ans=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)vis[j]=0;
		ans-=dfs(i);
	}
//	for(int i=1;i<=n;++i)printf("%d %d\n",tx[i],ty[i]);
	for(int i=1;i<=n;++i)if(!ty[i])go(i);
	printf("%d\n",ans);	
	return 0;
}

