/*
Author: CNYALI_LK
LANG: C++
PROG: scon.cpp
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
const ll N=19,M=33333,K=14456789,p=1000000007;
ll ein[M],a[N][N],f[M],g[M],et[N][M],eto[K],_2t3[M];
ll logs[M],p2[M];
int main(){
#ifdef cnyali_lk
	freopen("scon.in","r",stdin);
	freopen("scon.out","w",stdout);
#endif
	ll n,m,t;
	n=read(),m=read();t=1<<n;
	for(ll i=1;i<=m;++i)a[read()-1][read()-1]=1;
	for(ll i=0;i<n;++i)logs[1<<i]=i;
	for(ll i=0;i<n;++i)for(ll j=1;j<t;++j){
		et[i][j]=et[i][j^(j&(-j))]+a[i][logs[j&(-j)]];
	}
	p2[0]=1;
	for(ll i=1;i<t;++i){_2t3[i]=_2t3[i>>1]*3+(i&1);p2[i]=p2[i-1]*2%p;}
	for(ll i=1;i<t;++i){
		for(ll j=0;j<n;++j)if(i&(1<<j))ein[i]+=et[j][i];
//		printf("%lld\n",ein[i]);
	}
	for(ll i=1;i<t;++i)for(ll j=(t-1)^i;j;j=(j-1)&((t-1)^i)){
		eto[_2t3[i]+_2t3[j]+_2t3[j]]=eto[_2t3[i^(i&(-i))]+_2t3[j]+_2t3[j]]+et[logs[i&(-i)]][j];
	}
	for(ll i=1;i<t;++i){
		ll ka=i&(-i),kb=i^ka;
		g[i]=0;
		for(ll j=kb;j;j=(j-1)&kb){
			g[i]=(g[i]-g[j]*f[i-j]%p+p)%p;
		}
		f[i]=p2[ein[i]];
		for(ll j=i;j;j=(j-1)&i){
			f[i]=(f[i]-g[j]*p2[ein[i-j]+eto[_2t3[i-j]+2*_2t3[j]]]%p+p)%p;
		}
		g[i]=(g[i]+f[i])%p;
	}
	printf("%lld\n",f[t-1]);
	return 0;
}

