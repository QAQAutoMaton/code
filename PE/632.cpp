/*
Author: CNYALI_LK
LANG: C++
PROG: 632.cpp
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
ll pri[40005];
bool p[40005];
ll ps,fts[20000005],sti[20000005];
ll ans[105];
ll c[105][105];
const ll sq=31622,xblock=20000000,inf=0x3f3f3f3f;
void calc(ll n,ll m){
	fts[1]=0;
	for(ll i=2;i<=sq;++i){
		if(!p[i]){
			fts[i]=1;
			pri[++ps]=i;
		}
		for(ll j=1;j<=ps&&(ll)i*pri[j]<=sq;++j){
			p[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
	ll xl,xr,r;
	for(ll l=0;l<m;l+=xblock){
		debug("%lld:\n",l);
		r=l+xblock;
		for(ll i=1;i<=xblock;++i){fts[i]=0;sti[i]=i+l;}
		for(ll i=1;i<=ps;++i){
			xl=l/pri[i]+1;
			xr=r/pri[i];
			for(ll j=xl;j<=xr;++j){
				if(!(j%pri[i]))fts[j*pri[i]-l]=-inf;
				else ++fts[j*pri[i]-l];
				sti[j*pri[i]-l]/=pri[i];
			}
		}	
		for(ll i=1;i<=xblock;++i){
			if(sti[i]>1)++fts[i];
			if(fts[i]>=0)ans[fts[i]]+=n/(i+l)/(i+l);
		}
	}
}
const ll mod=1000000007;
int main(){
	freopen("632.in","r",stdin);
	freopen("632.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=0;i<=20;++i){
		c[i][0]=c[i][i]=1;
		for(ll j=1;j<i;++j)c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	calc(n,3000000000);
	ll xans=1;
	for(ll i=20;~i;--i){for(ll j=i+1;j<=20;++j)ans[i]-=ans[j]*c[j][i];if(ans[i])xans=xans*(ans[i]%mod)%mod;}
	printf("%lld\n",ans[7]);
	printf("%lld\n",xans);
	return 0;
}

