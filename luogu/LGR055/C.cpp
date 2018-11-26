/*
Author: CNYALI_LK
LANG: C++
PROG: C.cpp
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
typedef long long ll;
typedef pair<ll,ll> pii;
const ll inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
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
const ll M=1<<10,W=M-1,p=998244353; 
ll n,m;
ll f[M+5][M+5],cnt[M+5][M+5],w[M+5][M+5];
char s[25];
int main(){
#ifdef cnyali_lk
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	scanf("%lld%lld\n",&m,&n);
	ll x,y;
	for(ll i=1;i<=n;++i){
		y=0;
		scanf("%s%lld\n",s,&x);
		for(ll j=0;j<m;++j)y=y|((s[j]^'0')*(1<<j));
		w[y>>10][y&W]=x;
	}
	cnt[0][0]=1;f[0][0]=w[0][0];
	for(ll i=W;i;i=(i-1)&W)cnt[0][i]+=cnt[0][0],f[0][i]+=f[0][0];
	ll s,s2;
	for(ll i=1;i<(1<<m);++i){
		x=i>>10;
		y=i&W;
		s=0,s2=0;
		for(ll j=x;;j=(j-1)&x){
			s=s+f[j][y];
			s2=s2+cnt[j][y];
			if(!j)break;
		}
		s2%=p;
		s=(s+s2*w[x][y])%p;
		for(ll j=W^y;;j=(j-1)&(W^y)){
			f[x][j|y]=(f[x][j|y]+s)%p;
			cnt[x][j|y]=(cnt[x][j|y]+s2)%p;
			if(!j)break;
		}
	}
	printf("%lld\n",s);
	return 0;
}

