/*
Author: CNYALI_LK
LANG: C++
PROG: 2172.cpp
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
struct MF{
	int to[10260817],lst[10260817],w[10260817],beg[192608],e,n,cur[192608],dis[192608],q[192608],*l,*r;
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
			while(flow=dfs(s,t,0x3f3f3f3f))ans+=flow;
		}
		return ans;		
	}
};
MF Max_Flow;
char read_char(){
	char c;
	while((c=getchar())!='.'&&c!='x');
	return c;
}
int a[192][192],S[192][192],T[192][192];
int main(){
#ifdef cnyali_lk
	freopen("2172.in","r",stdin);
	freopen("2172.out","w",stdout);
#endif
	int n,m,r,c,s,t,cnt,f=0;
	s=1,t=cnt=2;
	n=read();m=read();r=read(),c=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		if(a[i][j]=(read_char()=='.')){
			S[i][j]=++cnt,T[i][j]=++cnt;
			++f;
			Max_Flow.add(s,S[i][j],1);
			Max_Flow.add(T[i][j],t,1);
		}
	}

	Max_Flow.n=cnt;
	for(int i=1;i<=n;++i){
		for(int j=c;j<=m;++j)if(a[i][j]&&a[i+r][j-c]){
			Max_Flow.add(S[i][j],T[i+r][j-c],1);
		}
		for(int j=1;j<=m-c;++j)if(a[i][j]&&a[i+r][j+c]){
			Max_Flow.add(S[i][j],T[i+r][j+c],1);
		}
		for(int j=r;j<=m;++j)if(a[i][j]&&a[i+c][j-r]){
			Max_Flow.add(S[i][j],T[i+c][j-r],1);
		}
		for(int j=1;j<=m-r;++j)if(a[i][j]&&a[i+c][j+r]){
			Max_Flow.add(S[i][j],T[i+c][j+r],1);
		}
	}
	printf("%d\n",f-Max_Flow.Max_Flow(s,t));
	return 0;
}

