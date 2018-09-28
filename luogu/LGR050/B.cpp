/*
Author: CNYALI_LK
LANG: C++
PROG: B.cpp
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
ll cnt[10485757];
void generate_array(ll a[], ll n, ll m, ll seed) {
    unsigned x = seed;
    for (ll i = 1; i <= n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        ++cnt[x % m + 1];
    }
	ll s=0;
	for(ll i=1;i<=m;++i)while(cnt[i]){
		--cnt[i];
		a[++s]=i;
	}
}
ll a[10485757],b[10485757],la,ra,lb,rb;
ll top(){
	ll xmn=0x3f3f3f3f3f3f3f3f;
	if(la<=ra){
		chkmin(xmn,a[la]);	
	}
	if(lb<=rb){
		chkmin(xmn,b[lb]);
	}
	return xmn;
}
void pop(){
	if(la<=ra &&lb>rb)++la;
	else if(lb<=rb&&la>ra)++lb;
	else if(a[la]<b[lb])++la;
	else ++lb;
}
void push(ll x){
	b[++rb]=x;
}
int main(){
#ifdef cnyali_lk
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	ll n,m,seed,xa,xb;
	n=read();m=read();seed=read();
	la=1,ra=n;
	lb=1;rb=0;
	generate_array(a,n,m,seed);
	for(ll i=1;i<n;++i){
		xa=top();
		pop();
		xb=top();
		if(xa+xa>xb){
			pop();
			push(xa*2);
		}
	}
	printf("%lld\n",top());
	return 0;
}

