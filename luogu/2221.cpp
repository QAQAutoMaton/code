/*
Author: CNYALI_LK
LANG: C++
PROG: 2221.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
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
ll rdc(){
	char c;
	while(!isalpha(c=getchar()));
	return c=='Q';
}
ll sum[3][102424];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
struct smt{
	ll s[3],add,ls,rs;
	smt *l,*r;
	void push_up(){
		for(ll i=0;i<3;++i)s[i]=l->s[i]+r->s[i];
	}
	void put_tag(ll x){
		if(x){
			add+=x;
			for(ll i=0;i<3;++i)s[i]+=x*(sum[i][rs]-sum[i][ls-1]);
		}
	}
	void push_down(){
		l->put_tag(add);
		r->put_tag(add);
		add=0;
	}
	smt(ll la,ll ra){
		ls=la;rs=ra;
		add=0;
		s[0]=s[1]=s[2]=0;
		if(la==ra){l=r=0;}
		else {
			ll mid=(la+ra)>>1;
			l=new smt(la,mid);
			r=new smt(mid+1,ra);
		}
	}
	void Add(ll la,ll ra,ll w){
		if(la<=ls&&rs<=ra)put_tag(w);
		else{
			push_down();
			if(la<=l->rs)l->Add(la,ra,w);
			if(r->ls<=ra)r->Add(la,ra,w);
			push_up();
		}
	}
	ll Sum(ll w,ll la,ll ra){
		if(la<=ls&&rs<=ra)return s[w];
		else{
			push_down();
			ll ans=0;
			if(la<=l->rs)ans+=l->Sum(w,la,ra);
			if(r->ls<=ra)ans+=r->Sum(w,la,ra);
			return ans;
		}
	}
}*rt;
int main(){
#ifdef cnyali_lk
	freopen("2221.in","r",stdin);
	freopen("2221.out","w",stdout);
#endif
	ll n,m,l,r,v,s1,s2,s0,s,t,g;
	n=read();m=read();
	for(ll i=1;i<=n;++i){
		sum[0][i]=sum[0][i-1]+1;
		sum[1][i]=sum[1][i-1]+i;
		sum[2][i]=sum[2][i-1]+i*i;
	}
	rt=new smt(1,n-1);
	for(;m;--m){
		if(rdc()){
			l=read();r=read();
			s0=rt->Sum(0,l,r-1);
			s1=rt->Sum(1,l,r-1);
			s2=rt->Sum(2,l,r-1);
			--l;
			s=s1*(r+l)-l*r*s0-s2;
			t=(r-l)*(r-l-1)>>1;
			g=gcd(s,t);
			printf("%lld/%lld\n",s/g,t/g);
		}	
		else{
			l=read();r=read();
			v=read();
			rt->Add(l,r-1,v);
		}
	}
	return 0;
}

