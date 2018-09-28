/*
Author: CNYALI_LK
LANG: C++
PROG: 3261.cpp
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
ll w[333333],l[333333],r[333333],add_tag[333333],mul_tag[333333],rlink[333333],fa[333333],a[333333],v[333333],in[333333];
ll h[333333],die[333333],dis[333333],root[333333],dsum[333333];
void put_add(ll x,ll y){add_tag[x]+=y;w[x]+=y;}
void put_mul(ll x,ll y){add_tag[x]*=y;w[x]*=y;mul_tag[x]*=y;}
void push_tag(ll x){
	put_mul(l[x],mul_tag[x]);
	put_mul(r[x],mul_tag[x]);
	put_add(l[x],add_tag[x]);
	put_add(r[x],add_tag[x]);
	add_tag[x]=0;
	mul_tag[x]=1;
}
ll merge(ll x,ll y){
	if(!x)return y;
	if(!y)return x;
	push_tag(x);
	push_tag(y);
	if(w[x]>w[y])swap(x,y);
	r[x]=merge(r[x],y);
	if(rlink[r[x]]>rlink[l[x]])swap(l[x],r[x]);
	rlink[x]=rlink[r[x]]+1;
	return x;
}
void remove(ll &x){
	push_tag(x);
	x=merge(l[x],r[x]);
}

int main(){
#ifdef cnyali_lk
	freopen("3261.in","r",stdin);
	freopen("3261.out","w",stdout);
#endif
	ll n,m;
	n=read();
	m=read();
	for(ll i=1;i<=n;++i)h[i]=read();
	dis[0]=-1;
	for(ll i=2;i<=n;++i){fa[i]=read(),a[i]=read(),v[i]=read();dis[i]=dis[fa[i]]+1;}
	for(ll i=1;i<=m;++i){mul_tag[i]=1;w[i]=read();in[i]=read();root[in[i]]=merge(root[in[i]],i);}
	for(ll i=n;i;--i){
		while(root[i]&&w[root[i]]<h[i]){
			die[root[i]]=i;
			remove(root[i]);
			++dsum[i];
		}	
		if(a[i])put_mul(root[i],v[i]);
		else put_add(root[i],v[i]);
		root[fa[i]]=merge(root[fa[i]],root[i]);
	}
	for(ll i=1;i<=n;++i)printf("%lld\n",dsum[i]);	
	for(ll i=1;i<=m;++i)printf("%lld\n",dis[in[i]]-dis[die[i]]);
	return 0;
}

