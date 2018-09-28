/*
Author: CNYALI_LK
LANG: C++
PROG: a.cpp
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
pii a[255],b[255];
ll n,m,k,t,w[255];
vector<ll> son[255];
ll dp[255][255][15],edp[255][255][15],siz[255][15],siz2[255][15],vis[255][15],col[255];
ll chk(ll l,ll r){
	for(ll i=l+1;i<r;++i)if(a[i].y>=a[l].y)return 0;
	return 1;
}
void dfs(ll x,ll kk){
	if(vis[x][kk])return;
	vis[x][kk]=1;
	for(ll i=0;i<=siz[x][kk];++i)dp[x][i][kk]=0;
	for(ll i=0;i<=siz2[x][kk];++i)edp[x][i][kk]=0;
	siz[x][kk]=siz2[x][kk]=0;	
	if(kk==k)return;
	for(auto s:son[x]){
		dfs(s,kk);
		dfs(s,kk+1);
		for(ll j=siz[x][kk];~j;--j)
			for(ll i=siz[s][kk];i;--i)
				chkmax(dp[x][i+j][kk],dp[x][j][kk]+dp[s][i][kk]);
		siz[x][kk]+=siz[s][kk];
		for(ll j=siz2[x][kk];~j;--j)
			for(ll i=siz[s][kk+1];i;--i)
				chkmax(edp[x][i+j][kk],edp[x][j][kk]+dp[s][i][kk+1]);
		siz2[x][kk]+=siz[s][kk+1];
	}
	if(x){
		for(ll i=siz2[x][kk];~i;--i)edp[x][i+1][kk]=edp[x][i][kk]+w[x];
		++siz2[x][kk];
	//	edp[x][1][kk]
		chkmax(siz[x][kk],siz2[x][kk]);
		for(ll i=0;i<=siz[x][kk];++i)chkmax(dp[x][i][kk],edp[x][i][kk]);
	}
}
int main(){
#ifdef cnyali_lk
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ll no=0;
	while(~scanf("%lld%lld%lld",&n,&m,&k)){
		for(ll i=1;i<=n;++i){
			a[i].x=read();a[i].y=read();
		}
		for(ll i=1;i<=n;++i)b[i]=make_pair(-a[i].y,i);
		sort(b+1,b+n+1);
		for(ll i=1;i<n;++i)col[i]=0;
		w[0]=-0x3f3f3f3f3f3f3f3f;
		for(ll i=0;i<=t;++i)son[i].erase(son[i].begin(),son[i].end());
		t=0;	
		for(ll i=2;i<=n;++i)if(b[i].x==b[i-1].x&&chk(b[i-1].y,b[i].y)){
			w[++t]=a[b[i].y].x-a[b[i-1].y].x;	
			son[col[b[i-1].y]].push_back(t);
			for(ll j=b[i-1].y;j<b[i].y;++j)col[j]=t;
		}	
		for(ll i=0;i<=n;++i)for(ll j=0;j<=k;++j)vis[i][j]=0;
		dfs(0,1);
		if(siz[0][1]<m)
			printf("Case %lld: -1\n",++no);
		else
			printf("Case %lld: %lld\n",++no,dp[0][m][1]);
	}	
	return 0;
}

