/*
Author: CNYALI_LK
LANG: C++
PROG: 1345.cpp
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
struct MF{
	int to[102423],lst[102423],w[102423],beg[102423],e,n,cur[102423],dis[102423],q[102423],*l,*r;
	MF(int N=0){e=1;n=N;for(int i=0;i<=n;++i)beg[i]=0;}
	void add(int u,int v,int flw){
		to[++e]=v;
		lst[e]=beg[u];
		beg[u]=e;
		w[e]=flw;
		to[++e]=u;
		lst[e]=beg[v];
		beg[v]=e;
		w[e]=0;
	}
	int bfs(int s,int t){
		for(int i=0;i<=n;++i)dis[i]=0x3f3f3f3f,cur[i]=beg[i];
		dis[s]=0;
		*(l=r=q)=s;
		while(l<=r){
			for(int i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(dis[to[i]],dis[*l]+1))*(++r)=to[i];
			++l;
		}	
		return dis[t]!=0x3f3f3f3f;
	}	
	int dfs(int s,int t,int flow){
		if(!flow)return 0;
		if(s==t)return flow;
#define i cur[s]
		for(;i;i=lst[i])if(w[i]&&dis[s]+1==dis[to[i]]){
			int fl=dfs(to[i],t,min(flow,w[i]));
			if(fl){
				w[i]-=fl;
				w[i^1]+=fl;
				return fl;
			}
		}	
#undef i
		return 0;
	}
	int Max_Flow(int s,int t){
		int ans=0,flow;
		while(bfs(s,t)){
			while(flow=dfs(s,t,0x3f3f3f3f)){
				ans+=flow;
			}
		}
		return ans;		
	}
};
MF Max_Flow;
int main(){
#ifdef cnyali_lk
	freopen("1345.in","r",stdin);
	freopen("1345.out","w",stdout);
#endif
	int n,m,s,t,u,v;
	n=read();m=read();s=read();t=read();
	Max_Flow.n=n*2;
	Max_Flow.add(s,s+n,0x3f3f3f3f);
	Max_Flow.add(t,t+n,0x3f3f3f3f);
	for(int i=1;i<=n;++i)Max_Flow.add(i,i+n,1);
	for(int i=1;i<=m;++i){
		u=read();v=read();
		Max_Flow.add(u+n,v,0x3f3f3f3f);
		Max_Flow.add(v+n,u,0x3f3f3f3f);
	}
	printf("%d\n",Max_Flow.Max_Flow(s,t));
	return 0;
}

