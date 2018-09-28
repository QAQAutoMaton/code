
/*
Author: CNYALI_LK
LANG: C++
PROG: 7.cpp
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

ll pm[23333333],pri[23333333],ps;
void init_phi(ll n){
	for(ll i=2;i<=n;++i){
		if(!pm[i]){
			pri[++ps]=i;
		}
		for(ll j=1;j<=ps&&i*pri[j]<=n;++j){
			pm[i*pri[j]]=1;
			if(!(i%pri[j]))break;
		}
	}
}

int main(){
#ifdef cnyali_lk
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
#endif
	init_phi(1000000);	
	printf("%lld\n",pri[10001]);
	return 0;
}

