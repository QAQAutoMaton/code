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
const ll N=23333333;
ll p[N],pri[N],ps;
ll phi[N];
void init_phi(ll n){
	phi[1]=1;
	ll ans=0,kk=1;
	for(ll i=2;i<=n;++i){
		if(!p[i]){
			pri[++ps]=i;
			phi[i]=i-1;
		}
		for(ll j=1;j<=ps&&i*pri[j]<=n;++j){
			p[i*pri[j]]=1;
			if(i%pri[j])phi[i*pri[j]]=phi[i]*(pri[j]-1);
			else {phi[i*pri[j]]=phi[i]*pri[j];break;}
		}
	}
}
ll n,m,a[504321];
void add(ll x,ll y){
	while(x<=n){
		a[x]+=y;
		x+=x&(-x);
	}
}
ll sum(ll x){
	ll y=0;
	while(x){
		y+=a[x];
		x^=x&(-x);
	}
	return y;
}
ll query(ll l,ll r,ll p){
	ll a=sum(l),b,gugugu=0;
	if(a>=p)gugugu=1;
	a%=p;
	if(p==1||l==r){
		return a+gugugu*p; 
	}
	b=query(l+1,r,phi[p]);
	ll c=1;
	while(b){
		if(b&1)c=c*a;
		if(c>=p)gugugu=1;
		c%=p;
		b>>=1;
		a=a*a;
		if(b&&a>=p)gugugu=1;
		a%=p;
	}
	return c+gugugu*p;
}
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	init_phi(20000000);
	n=read();m=read();
	ll lst=0,ths;
	for(ll i=1;i<=n;++i){
		ths=read();
		add(i,ths-lst);
		lst=ths;
	}
	ll l,r,x;
	for(;m;--m){
		if(read()^2){
			l=read();r=read();
			x=read();
			add(l,x);
			add(r+1,-x);
		}
		else{
			l=read();
			r=read();
			x=read();
			printf("%lld\n",query(l,r,x)%x);
		}
	}	

	return 0;

}

