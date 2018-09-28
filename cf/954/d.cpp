/*
Author: CNYALI_LK
LANG: C++
PROG: d.cpp
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
int a[1926][1926];
int dis1[1926],dis2[1926];
vector<int> to[1926];

int n,m,s,t,u,v;
int q[192608];
void bfs(int s,int *dis){
	int *l,*r;
	l=r=q;
	*q=s;
	while(l<=r){
		for(auto i:to[*l])if(i!=s&&!dis[i])dis[i]=dis[*l]+1,*(++r)=i;
		++l;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	n=read();
	m=read();
	s=read();t=read();
	for(int i=1;i<=m;++i){
		u=read();v=read();
		a[u][v]=a[v][u]=1;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	bfs(s,dis1);
	bfs(t,dis2);
	int cnt=0;
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if((!a[i][j])&&dis1[i]+dis2[j]+1>=dis1[t]&&dis1[j]+dis2[i]+1>=dis1[t]){++cnt;}
	printf("%d\n",cnt);
	return 0;
}

