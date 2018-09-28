/*
Author: CNYALI_LK
LANG: C++
PROG: 2045.cpp
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
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
int a[64][64],in[64][64],out[64][64];
struct MCF{
	int to[1926081],lst[1926081],w[1926081],c[1926081],beg[1926081],e,n,MinCost,dis[1926081],q[19260817],*l,*r,pre[1926081],flw[1926081],inq[1926081];
	MCF(){
		e=1;
		MinCost=0;
	}
	void add(int u,int v,int flow,int cost){
		to[++e]=v;
		lst[e]=beg[u];
		beg[u]=e;
		w[e]=flow;
		c[e]=cost;
		to[++e]=u;
		lst[e]=beg[v];
		beg[v]=e;
		w[e]=0;
		c[e]=-cost;
	}
	int spfa(int s,int t){
		*(l=r=q)=s;	
		for(int i=1;i<=n;++i)dis[i]=0x3f3f3f3f,flw[i]=0,pre[i]=0;
		dis[s]=0;
		flw[s]=0x3f3f3f3f;
		inq[s]=1;
		while(l<=r){
			for(int i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(dis[to[i]],dis[*l]+c[i])){
				flw[to[i]]=min(flw[*l],w[i]);
				pre[to[i]]=i;
				if(!inq[to[i]])*(++r)=to[i];	
			}
			inq[*l]=0;
			++l;
		}
		if(flw[t]){
			int h=t;
			while(pre[h]){
				int i=pre[h];
				w[i]-=flw[t];
				w[i^1]+=flw[t];
				MinCost+=c[i]*flw[t];
				h=to[i^1];
			}	
		}
		return flw[t];
	}
	int Min_Cost_Flow(int s,int t){
		while(spfa(s,t));
		return MinCost;
	}
};
MCF Min_Cost_Flow;
int main(){
#ifdef cnyali_lk
	freopen("2045.in","r",stdin);
	freopen("2045.out","w",stdout);
#endif
	int n,k;
	n=read();k=read();
	int s=1,t=2,nt=2;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
		a[i][j]=read();
		in[i][j]=++nt;
		out[i][j]=++nt;
		Min_Cost_Flow.add(in[i][j],out[i][j],1,-a[i][j]);
		Min_Cost_Flow.add(in[i][j],out[i][j],0x3f3f3f3f,0);
	}
	Min_Cost_Flow.n=nt;
	Min_Cost_Flow.add(s,in[1][1],k,0);
	Min_Cost_Flow.add(out[n][n],t,k,0);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
		if(i<n)
			Min_Cost_Flow.add(out[i][j],in[i+1][j],0x3f3f3f3f,0);
		if(j<n)
			Min_Cost_Flow.add(out[i][j],in[i][j+1],0x3f3f3f3f,0);
	}
	printf("%d\n",-Min_Cost_Flow.Min_Cost_Flow(s,t));
	return 0;
}

