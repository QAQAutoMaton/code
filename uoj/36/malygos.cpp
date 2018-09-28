/*
Author: CNYALI_LK
LANG: C++
PROG: malygos.cpp
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
typedef unsigned long long ll;
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
ll linear[66],basis[66],k,s[66],a[233333];
void insert(ll x){
	for(ll i=60;~i;--i){
		if(x&(1LL<<i))
			if(linear[i]) x^=linear[i];
		else{
			linear[i]=x;
			for(ll j=i-1;~j;--j)if(linear[i]&(1LL<<j))linear[i]^=linear[j];
			for(ll j=60;j>i;--j)if(linear[j]&(1LL<<i))linear[j]^=linear[i];
			k=0;
			for(ll j=0;j<60;++j)if(linear[j]){basis[k]=linear[j];++k;}
			break;
		}
	}
	
}
int main(){
#ifdef cnyali_lk
	freopen("malygos.in","r",stdin);
	freopen("malygos.out","w",stdout);
#endif
	ll n,m;
	n=read();
	m=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	if(m==1){
		ll ans=0;
		for(ll i=1;i<=n;++i)ans|=a[i];
		if(ans&1)printf("%llu.5\n",ans>>1);
		else printf("%llu\n",ans>>1);
	}
	else if(m==2){
		ll res=0,ans=0;
		for(ll i=0;i<32;++i)for(ll j=0;j<32;++j){
			ll as,b,c;
			as=b=c=0;
			for(ll k=1;k<=n;++k){
				if(!!(a[k]&(1LL<<i))!=!!(a[k]&(1LL<<j)))as=1;			
				if(a[k]&(1LL<<i))b=1;			
				if(a[k]&(1LL<<j))c=1;			
			}
			if(b&&c){
				if((int)(i+j)-1-(int)as<0)++res;
				else{
					ans+=1ULL<<(i+j-1-as);
				}
			}
		}
		ans=ans+(res>>1);
		res&=1;
		printf("%llu%s",ans,res?".5\n":"\n");
	}
	else{
		for(ll i=1;i<=n;++i)insert(a[i]);	
		ll ans=0,res=0;
		for(ll i=0;i<(1<<k);++i){
			ll as=0,xres=1,sum=0;
			for(ll j=0;j<k;++j)if(i&(1<<j))as^=basis[j];
			for(ll l=1;l<=m;++l){
				sum=sum*as;
				xres=xres*as;
				sum+=xres>>k;
				xres&=(1<<k)-1;
			}	
			res+=xres;
			ans+=sum+(res>>k);
			res&=(1<<k)-1;
		}
		printf("%llu%s",ans,res?".5\n":"\n");
	}
	return 0;
}

