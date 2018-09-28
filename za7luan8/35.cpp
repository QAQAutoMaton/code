/*
Author: CNYALI_LK
LANG: C++
PROG: 35.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
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
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
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
ll bat[102423],dis1[102423],dis2[102423],dis3[102423],out[102423];
ll beg[102423],to[204847],lst[204847],w1[204847],w2[204847],e;
ll n,m,k,s,t,u,v,p,q;
void add(ll u,ll v,ll p,ll q){
	to[++e]=v;
	lst[e]=beg[u];
	beg[u]=e;
	w1[e]=p;
	w2[e]=q;
}
priority_queue<pii,vector<pii>,greater<pii> >pq;
void dij1(){
	for(ll i=1;i<=n;++i)dis1[i]=0x3f3f3f3f3f3f3f3f,out[i]=0;
	dis1[t]=0;
	while(!pq.empty())pq.pop();
	pq.push(make_pair(0,t));
	ll x,wa;
	while(!pq.empty()){
		x=pq.top().y;
		wa=pq.top().x;
		pq.pop();
		if(out[x])continue;
		out[x]=1;
		for(ll i=beg[x];i;i=lst[i])if(chkmin(dis1[to[i]],wa+w1[i]))pq.push(make_pair(dis1[to[i]],to[i]));
	}
}

void dij2(){
	for(ll i=1;i<=n;++i)dis2[i]=0x3f3f3f3f3f3f3f3f,out[i]=0;
	dis2[s]=0;
	while(!pq.empty())pq.pop();
	pq.push(make_pair(0,s));
	ll x,wa;
	while(!pq.empty()){
		x=pq.top().y;
		wa=pq.top().x;
		pq.pop();
		if(out[x])continue;
		out[x]=1;
		for(ll i=beg[x];i;i=lst[i])if(chkmin(dis2[to[i]],wa+w2[i]))pq.push(make_pair(dis2[to[i]],to[i]));
	}
}

void dij3(){
	for(ll i=1;i<=n;++i)dis3[i]=0x3f3f3f3f3f3f3f3f,out[i]=0;

	while(!pq.empty())pq.pop();
	for(ll i=1;i<=k;++i)pq.push(make_pair(dis3[bat[i]]=-dis1[bat[i]],bat[i]));
	ll x,wa;
	while(!pq.empty()){
		x=pq.top().y;
		wa=pq.top().x;
		pq.pop();
		if(out[x])continue;
		out[x]=1;
		for(ll i=beg[x];i;i=lst[i])if(chkmin(dis3[to[i]],wa+w1[i]))pq.push(make_pair(dis3[to[i]],to[i]));
	}
}
int main(){
#ifdef cnyali_lk
	freopen("35.in","r",stdin);
	freopen("35.out","w",stdout);
#endif
	n=read();m=read();k=read();s=read();t=read();
	for(ll i=1;i<=k;++i)bat[i]=read();
	for(ll i=1;i<=m;++i){
		u=read();v=read();p=read();q=read();
		add(u,v,p,q);
		add(v,u,p,q);
	}
	dij1();
	ll sum=0,ans=0x3f3f3f3f3f3f3f3f;
	for(ll i=1;i<=k;++i)sum+=dis1[bat[i]];
	dij2();
	dij3();
	for(ll i=1;i<=n;++i)chkmin(ans,sum+dis1[i]+dis2[i]+dis3[i]);
	printf("%lld\n",ans);
	return 0;
}

