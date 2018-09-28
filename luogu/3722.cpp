/*
Author: CNYALI_LK
LANG: C++
PROG: 3722.cpp
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
char WritellBuffer[1024];
template<class T>void write(T a,char end){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
struct _ask{
	ll t,l,r;
	_ask(){}
	_ask(ll _t){
		t=_t;
		l=read();r=read();
	}
};
_ask ask[204847];

ll n,m,p1,p2;
ll a[204847];
struct smt{
	smt *l,*r;
	ll _l,_r,sum,add;
#define push_up sum=l->sum+r->sum
	smt(ll ls,ll rs){
		_l=ls;_r=rs;
		sum=add=0;
		if(ls!=rs){
			ll mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
		}
	}
	void put_tag(ll w){
		sum+=w*(_r-_l+1);
		add+=w;
	}
	void push_down(){
		l->put_tag(add);
		r->put_tag(add);
		add=0;
	}
	void change(ll ls,ll rs,ll w){
		if(ls<=_l&&_r<=rs)put_tag(w);
		else{
			push_down();
			if(ls<=l->_r)l->change(ls,rs,w);
			if(rs>=r->_l)r->change(ls,rs,w);
			push_up;
		}
	}
	ll query(ll ls,ll rs){
		if(ls<=_l&&_r<=rs)return sum;
		else{
			push_down();
			ll ans=0;
			if(ls<=l->_r)ans+=l->query(ls,rs);
			if(rs>=r->_l)ans+=r->query(ls,rs);
			return ans;
		}
	}
};
ll nx[204847],ans[204847];
void calc(){
	sort(ask+1,ask+m+1,[](_ask a,_ask b){return a.l<b.l;});
	stack<ll> stk;
	stk.push(n+1);
	smt *r=new smt(1,n+1);
	ll j=m;
	for(ll i=n;i;--i){
		while(a[stk.top()]<a[i])stk.pop();
		nx[i]=stk.top();
		stk.push(i);
		r->change(i+1,nx[i],p2);
		r->change(nx[i],nx[i],p1-2*p2);
		while(ask[j].l==i){
			ans[ask[j].t]+=r->query(1,ask[j].r);
			--j;
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("3722.in","r",stdin);
	freopen("3722.out","w",stdout);
#endif
	n=read();
	m=read();p1=read();p2=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	a[n+1]=n+1;
	for(ll i=1;i<=m;++i){
		 ask[i]=_ask(i);
	}
	calc();
	reverse(a+1,a+n+1);
	for(ll i=1;i<=m;++i){ask[i].l=n+1-ask[i].l;ask[i].r=n+1-ask[i].r;swap(ask[i].l,ask[i].r);}
	calc();
	for(ll i=1;i<=m;++i)write(ans[i],'\n');
	return 0;
}

