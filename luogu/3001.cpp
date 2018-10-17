/*
Author: CNYALI_LK
LANG: C++
PROG: 3001.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define double long double
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
double dis[2047],w[50005],V;
int beg[2047],to[50005],lst[50005],e,cnt[2047];
void add(int u,int v,double c){to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=c;}
int n,m,a,b;
int q[2047],*l,*r,inq[2047];
int *nxt(int *a){
	if(a==q+2046)return q;
	return a+1;
}
void spfa(int s){
	for(int i=1;i<=n;++i)dis[i]=1e16,inq[i]=0;
	dis[s]=0;
	inq[*(l=r=q)=s]=1;	
	while(l!=nxt(r)){
		inq[*l]=0;
		for(int i=beg[*l];i;i=lst[i])if(dis[to[i]]>dis[*l]+w[i]+eps){
			dis[to[i]]=dis[*l]+w[i];

			if(!inq[to[i]]){
				*(r=nxt(r))=to[i];
				inq[to[i]]=1;
				if(++cnt[to[i]]>=n){printf("0\n");exit(0);}
			}
		}
		l=nxt(l);
	}
}
int main(){
#ifdef cnyali_lk
	freopen("3001.in","r",stdin);
	freopen("3001.out","w",stdout);
#endif
	n=read();m=read();scanf("%Lf",&V);a=read();b=read();
	int u,v;
	double w;
	for(;m;--m){
		scanf("%d%d%Lf",&u,&v,&w);	
		w=log(w);
		add(u,v,w);
//		add(v,u,-w);
	}
	spfa(a);
	printf("%.8Lf\n",exp(dis[b])*V);
	return 0;
}

