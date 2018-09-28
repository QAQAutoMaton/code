/*
Author: CNYALI_LK
LANG: C++
PROG: 625.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
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
const ll p=998244353;
const ll i2=(p+1)>>1;
ll pm[23333333],pri[23333333],fs[23333333],n,m,ps;
tr1::unordered_map<ll,ll> Fs;
ll G(ll n){
	return n%p;
}
ll S(ll n){
	n=n%p;
	return n*(n+1)%p*i2%p;
}

ll F(ll n){
	if(n<=m)return fs[n];
	if(Fs.count(n))return Fs[n];
	ll ans=S(n);
	ll l=2,r;
	while(l<=n){
		r=n/(n/l);
		ans=(ans-(G(r)-G(l-1)+p)*F(n/l)%p+p)%p;
		l=r+1;
	}
	return Fs[n]=ans;
}
void init_phi(ll n){
	fs[1]=1;
	for(ll i=2;i<=n;++i){
		if(!pm[i]){
			pri[++ps]=i;
			fs[i]=i-1;
		}
		for(ll j=1;j<=ps&&i*pri[j]<=n;++j){
			pm[i*pri[j]]=1;
			if(i%pri[j])fs[i*pri[j]]=fs[i]*(pri[j]-1);
			else{fs[i*pri[j]]=fs[i]*pri[j];break;}
		}
		fs[i]=(fs[i]+fs[i-1])%p;
	}
}
template<class T>T sqr(T a){return a*a%p;}
int main(){
#ifdef cnyali_lk
	freopen("625.in","r",stdin);
	freopen("625.out","w",stdout);
#endif
	n=read();
	m=(ll)(ceil(pow(n,((long double)2)/3)));
	init_phi(m);
	ll ans=0,l,r;
	l=1;r=0;
	while(l<=n){
		ans-=F(r)*sqr((n/l)%p)%p;
		r=n/(n/l);
		ans+=F(r)*sqr((n/l)%p)%p+p;
		ans%=p;
		l=r+1;
	}
	printf("%lld\n",ans);
	ans=(ans+n%p*(n%p+1)%p*i2)%p;
	ans=ans*i2%p;
	printf("%lld\n",ans);

	return 0;
}

