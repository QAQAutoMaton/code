/*
Author: CNYALI_LK
LANG: C++
PROG: c.cpp
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
ll m;
ll w[1024242],a[1024242],rfa[1024242],fa[1024242],dfn[1024242],low[1024242],ins[1024242],stk[1024242],col[1024242],top,t;
ll siz[1024242],need[1024242],have[1024242];
void dfs(ll x){
	dfn[x]=low[x]=++t;
	ins[x]=1;
	stk[++top]=x;
	if(dfn[rfa[x]])
		if(ins[fa[x]])chkmin(low[x],dfn[rfa[x]]);
		else;
	else{
		dfs(rfa[x]);
		chkmin(low[x],low[rfa[x]]);
	}
	if(dfn[x]==low[x]){
		stk[top+1]=-1;
		++m;
		for(;stk[top+1]!=x;--top){
			ins[stk[top]]=0;
			w[col[stk[top]]=m]+=a[stk[top]];
			++siz[m];
		}
	}
}
ll check(ll x){
	for(ll i=0;i<=m;++i){
		have[i]=w[i];
		need[i]=x*siz[i];	
	}
	for(ll i=m;i;--i)if(have[i]<need[i]){have[fa[i]]-=need[i]-have[i];have[i]=need[i];}
	return have[0]>=0;
}
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	ll n;	
	n=read();w[0]=read();
	for(ll i=1;i<=n;++i){
		rfa[i]=read();
		if(rfa[i]==-1)rfa[i]=0;
	}
	for(ll i=1;i<=n;++i)a[i]=read();
	ll l=w[0],r=w[0];
	for(ll i=1;i<=n;++i){chkmin(l,a[i]);r+=a[i];}
	r/=n;
	dfn[0]=t=1;	
	for(ll i=1;i<=n;++i)if(!dfn[i])dfs(i);
	for(ll i=1;i<=n;++i)if(col[i]!=col[rfa[i]])fa[col[i]]=col[rfa[i]];
	ll mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",l-1);
	return 0;
}

