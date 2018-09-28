/*
Author: CNYALI_LK
LANG: C++
PROG: std.cpp
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
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
ll s[127];
int main(){
	ll t,k,u,v;
	t=read();k=read();
	if(k==1){
		while(t){
			--t;
			u=read();v=read();
			printf("%lld\n",min(u,v));
		}
	}
	else{
		s[0]=1;
		ll h=1,u,v,disu,disv;
		for(ll i=1;i<=100;++i){
			s[i]=s[i-1]+h;
			h*=k;
		}
		for(;t;--t){
			u=read();v=read();
			if(u<v)swap(u,v);
			for(ll i=1;i<=100;++i)if(s[i]>u){disu=i-1;break;}
			for(ll i=1;i<=100;++i)if(s[i]>v){disv=i-1;break;}
			u-=s[disu];
			v-=s[disv];
			while(disu>disv){
				u/=k;
				--disu;
			}
			while(u!=v){
				u/=k;v/=k;
				--disu;--disv;
			}
			printf("%lld\n",u+s[disu]);
		}
	}
	return 0;
}

