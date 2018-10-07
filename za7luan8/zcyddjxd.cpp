/*
Author: CNYALI_LK
LANG: C++
PROG: zcyddjxd.cpp
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
template<class T>inline void read(T &s){
	s=0;
	ll base=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=1;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	if(base)s=-s;
}
template<class T,class... U> inline void read(T &a,U&... b){
	read(a);read(b...);
}
const ll orz=998244353;
ll p[1023],f[1023][5],s[1023];
ll put(ll n,ll x,ll y){
	return x*(x-1)-s[x-1]+s[n]-s[y]-y*(n-y)-max(x-y,0LL);
}
int main(){
#ifdef cnyali_lk
	freopen("zcyddjxd.in","r",stdin);
	freopen("zcyddjxd.out","w",stdout);
#endif
	ll t,n;
	read(t);
	n=1005;
	f[0][0]=1;
	f[0][1]=1;
	f[0][2]=2;
	for(ll i=1;i<=n;++i){
		s[i]=s[i-1]+i;
		if(i>1)f[i][0]=(i-1)*(f[i-1][0]+f[i-2][0])%orz;
		for(ll j=1;j<=2;++j)f[i][j]=(f[i][j-1]*j+f[i-1][j]*i)%orz;
	} 
	for(;t;--t){
		read(n);
		for(ll i=1;i<=n;++i)read(p[i]);
		ll cnt=0,s0,s1,s2,qaq;
		qaq=0;
		for(ll i=1;i<=n;++i)for(ll j=1;j<i;++j)qaq=qaq+(i-j);
		for(ll i=1;i<=n;++i)for(ll j=i+1;j<=n;++j){
			s0=max(p[j]-p[i],0LL);
			s1=((p[j]-1)*p[j]-s[p[j]-1])+(s[n]-s[p[i]]-(n-p[i])*p[i])-s0*2;
			s2=qaq-s0-s1-put(n,p[i],p[j]);
			cnt+=(s0*f[n-2][0]+s1*f[n-3][1]+s2*f[n-4][2])%orz*(j-i)%orz;
		}
		printf("%lld\n",cnt%orz);
	}
	return 0;
}

