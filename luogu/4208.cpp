/*
Author: CNYALI_LK
LANG: C++
PROG: 4208.cpp
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
struct edge{
	int u,v,w;
};
edge e[102424];
int fa[102424];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int e_cmp(edge a,edge b){return a.w<b.w;}
const int p=31011;
double a[128][128];
int main(){
#ifdef cnyali_lk
	freopen("4208.in","r",stdin);
	freopen("4208.out","w",stdout);
#endif
	int n,m;
	n=read();m=read();
	for(int i=1;i<=m;++i){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	sort(e+1,e+m+1,e_cmp);
	for(int i=1;i<=n;++i)fa[i]=i;
	int g=n;
	for(int i=1;i<=m&&g>1;++i)if(find(e[i].u)!=find(e[i].v)){
		use[i]=1;	
		--g;
	}
	if(g>1){printf("0\n");return 0;}
	int u=1,v=1;
	int ans=1;
	for(v<=m){
		for(int i=1;i<=n;++i){
			fa[i]=i;
			is[i]=0;
		}
		for(int i=1;i<=m;++i)if(use[i]&&e[i].w!=e[u].w){
			fa[find(e[i].u)]=find(e[i].v);	
		}	
		g=0;
		for(int i=1;i<=n;++i){
			if(!is[find(i)]){
				is[find(i)]=++g;
			}
			is[i]=is[find(i)];
		}
		--g;
		for(int i=1;i<=g;++i)for(int j=1;j<=g;++j)a[i][j]=0;
		while(e[u].w==e[v].w){
			a[is[e[i].u]][is[e[i].v]]-=1;
			a[is[e[i].v]][is[e[i].u]]-=1;
			a[is[e[i].u]][is[e[i].u]]+=1;
			a[is[e[i].v]][is[e[i].v]]+=1;
			++v;
		}
		ans=ans*(int)det(g)%p;
		u=v;
	}
	return 0;
}

