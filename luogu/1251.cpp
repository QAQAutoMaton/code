/*
Author: CNYALI_LK
LANG: C++
PROG: 1251.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char WritellBuffer[1024];
template<class T>void write(T a,char end){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
ll dirty[102424],clean[102424],t,s;
ll r[102424],p,tq,cq,ts,cs;
struct MCF{
	ll to[102424],lst[102424],w[102424],c[102424],beg[102424],e,n;
	ll mincost,dis[102424],pre[102424],flow[102424];
	MCF(){
		e=1;
	}
	void add(ll u,ll v,ll flow,ll cost){
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
	ll q[1204848],*l,*r,inq[102424];
	ll spfa(ll s,ll t){
		for(ll i=1;i<=n;++i)dis[i]=0x3f3f3f3f3f3f3f3f,pre[i]=-1,flow[i]=0;
		*(l=r=q)=s;
		dis[s]=0;
		pre[s]=0;
		inq[s]=1;
		flow[s]=0x3f3f3f3f3f3f3f3f;
		while(l<=r){
			for(ll i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(dis[to[i]],dis[*l]+c[i])){
				pre[to[i]]=i^1;
				flow[to[i]]=min(flow[*l],w[i]);
				if(!inq[to[i]]){
					inq[*(++r)=to[i]]=1;
				}
			}
			inq[*l]=0;
			++l;
		}
		
		if(!flow[t])return 0;
		ll h=t,i;
		while(pre[h]){
			i=pre[h];
			w[i]+=flow[t];
			w[i^1]-=flow[t];
			mincost+=c[i^1]*flow[t];
			h=to[i];
		}
		return 1;
	}
	ll solve(ll s,ll t){
		mincost=0;
		while(spfa(s,t));
		return mincost;
	}
};
MCF Min_Cost_Flow;
int main(){
#ifdef cnyali_lk
	freopen("1251.in","r",stdin);
	freopen("1251.out","w",stdout);
#endif
	ll n;
	n=read();
	s=1;
	t=(n+1)<<1;
	Min_Cost_Flow.n=t;
	for(ll i=1;i<=n;++i)dirty[i]=i<<1,clean[i]=i<<1|1;
	for(ll i=1;i<=n;++i){
		r[i]=read();
	}
	p=read();tq=read();cq=read();ts=read();cs=read();
	for(ll i=1;i<=n;++i){
		Min_Cost_Flow.add(s,dirty[i],r[i],0);
		Min_Cost_Flow.add(s,clean[i],r[i],p);
		Min_Cost_Flow.add(clean[i],t,r[i],0);
		Min_Cost_Flow.add(dirty[i],dirty[i+1],0x3f3f3f3f3f3f3f3f,0);
		Min_Cost_Flow.add(dirty[i],clean[i+tq],0x3f3f3f3f3f3f3f3f,cq);
		Min_Cost_Flow.add(dirty[i],clean[i+ts],0x3f3f3f3f3f3f3f3f,cs);
	}
	printf("%lld\n",Min_Cost_Flow.solve(s,t));
	return 0;
}

