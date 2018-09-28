/*
Author: CNYALI_LK
LANG: C++
PROG: 3953.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
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
int to[204847],lst[204847],w[204847],beg[102423],e;
int ito[204847],ilst[204847],iw[204847],ibeg[102423],ie;
int _to[10242047],_lst[10242047],_beg[5121023],_e;
int dis_s[204847],dis_t[204847];
int q[10242047],*l,*r;
int t,u,v,n,m,k,p;
__gnu_pbds::priority_queue<pii,greater<pii> > pq;
__gnu_pbds::priority_queue<pii,greater<pii> >::point_iterator it[102423];
#define x first
#define y second
void dijkstra(int s,int *dis){
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;++i){
		it[i]=pq.push(make_pair(dis[i]=(i==s)?0:0x3f3f3f3f,i));
	}
	int a;
	while(!pq.empty()&&pq.top().x!=0x3f3f3f3f){
		a=pq.top().y;	
		pq.pop();
		for(int i=beg[a];i;i=lst[i]){
			if(chkmin(dis[to[i]],dis[a]+w[i]))pq.modify(it[to[i]],make_pair(dis[to[i]],to[i]));
		}
	}
} 
void idijkstra(int s,int *dis){
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;++i){
		it[i]=pq.push(make_pair(dis[i]=(i==s)?0:0x3f3f3f3f,i));
	}
	int a;
	while(!pq.empty()&&pq.top().x!=0x3f3f3f3f){
		a=pq.top().y;	
		pq.pop();
		for(int i=ibeg[a];i;i=ilst[i]){
			if(chkmin(dis[ito[i]],dis[a]+iw[i]))pq.modify(it[ito[i]],make_pair(dis[ito[i]],ito[i]));
		}
	}
} 
int in_deg[5121023],f[5121023];
void add(int u,int v,int _w){
	to[++e]=v;
	lst[e]=beg[u];
	beg[u]=e;
	w[e]=_w;
	ito[++ie]=u;
	ilst[ie]=ibeg[v];
	ibeg[v]=ie;
	iw[e]=_w;
}
void _add(int u,int v){
	_to[++_e]=v;
	_lst[_e]=_beg[u];
	_beg[u]=_e;
	++in_deg[v];
}
void Plus(int &a,int b){
	if((a+=b)>=p)a-=p ;
}
void top_sort(){
	while(l<=r){
		for(int i=_beg[*l];i;i=_lst[i]){
			Plus(f[_to[i]],f[*l]);
			if(!(--in_deg[_to[i]]))*(++r)=_to[i];	
		}
		++l;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("3953.in","r",stdin);
	freopen("3953.out","w",stdout);
#endif
	t=read();
	do{
		n=read();m=read();k=read();p=read();
		e=ie=0;
		_e=0;
		for(int i=1;i<=n;++i){
			beg[i]=ibeg[i]=0;
			for(int j=0;j<=k;++j){	_beg[i+j*n]=in_deg[i+j*n]=0;f[i+j*n]=i==1;}
		}
		while(m){
			--m;
			u=read(),v=read();
			add(u,v,read());
		}
		dijkstra(1,dis_s);
		idijkstra(n,dis_t);
		for(int i=1;i<=n;++i){
			for(int j=beg[i];j;j=lst[j]){
				u=i;v=to[j];
				if(dis_s[u]+w[j]+dis_t[v]<=dis_t[1]+k){
					for(int _k=w[j]+dis_s[u]-dis_s[v],_ik=0;_k<=k;++_k,++_ik){
						_add(u+_ik*n,v+_k*n);
					}
				}
			}
		}
		*(l=r=q)=1;
		for(int i=1;i<=k;++i){
			*(++r)=i*n+1;
		}
		top_sort();
		if(in_deg[n*(k+1)])printf("-1\n");
		else printf("%d\n",f[n*(k+1)]);
	}
	while(--t);
	return 0;
}

