/*
Author: CNYALI_LK
LANG: C++
PROG: f.cpp
Mail: cnyalilk@vip.qq.com
*/ #include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.ed()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
const ll p=998244353;
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
template<class T>void write(T a,char ed){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(ed);
}
ll h[66666],l[66666],r[66666],a[66666];
ll ok[4][66666];
ll beg[4][66666],ed[4][66666];
ll fpm(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1)c=c*a%p;
		a=a*a%p;
		b>>=1;
	}
	return c;
}
void py(ll x,ll ok1,ll ok2,ll ok3){
	if(h[x]+1==h[x+1]){
		ed[1][x]=beg[1][x];
		ed[2][x]=beg[2][x];
		ed[3][x]=beg[3][x];
	}
	else{
		if(ok1&&ok2&&ok3){
			ed[1][x]=beg[1][x]*fpm(3,h[x+1]-h[x])%p;
			ed[2][x]=beg[2][x]*fpm(3,h[x+1]-h[x])%p;
			ed[3][x]=beg[3][x]*fpm(3,h[x+1]-h[x])%p;
		}
		else if(ok1&&ok2){
			ed[1][x]=beg[1][x]*fpm(2,h[x+1]-h[x])%p;
			ed[2][x]=beg[2][x]*fpm(2,h[x+1]-h[x])%p;
		}	
		else if(ok2&&ok3){
			ed[3][x]=beg[3][x]*fpm(2,h[x+1]-h[x])%p;
			ed[2][x]=beg[2][x]*fpm(2,h[x+1]-h[x])%p;
		}else{
			ed[1][x]=beg[1][x];
			ed[2][x]=beg[2][x];
			ed[3][x]=beg[3][x];
		}
	}
}
void jy(ll x){
	beg[1][x+1]=ed[1][x];
	beg[2][x+1]=ed[2][x];
	beg[3][x+1]=ed[3][x];
	if(ok[1][x+1]&&ok[2][x+1])beg[1][x+1]+=ed[2][x],beg[2][x+1]+=ed[1][x];
	if(ok[3][x+1]&&ok[2][x+1])beg[3][x+1]+=ed[2][x],beg[2][x+1]+=ed[3][x];
	if(ok[3][x+1]&&ok[2][x+1]&&ok[1][x+1]){
		beg[3][x+1]+=ed[1][x],beg[1][x+1]+=ed[3][x];
	}
	++x;
	beg[1][x]%=p;
	beg[2][x]%=p;
	beg[3][x]%=p;
	if(!ok[1][x])beg[1][x]=0;
	if(!ok[2][x])beg[2][x]=0;
	if(!ok[3][x])beg[3][x]=0;
}
int main(){
#ifdef cnyali_lk
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	ll n,m,t=0;
	n=read();m=read();
	h[++t]=1;h[++t]=m+1;
	for(ll i=1;i<=n;++i){
		a[i]=read();
		l[i]=read();
		r[i]=read();
		h[++t]=l[i];
		h[++t]=++r[i];
	}
	sort(h+1,h+t+1);
	t=unique(h+1,h+t+1)-h-1;
	for(ll i=1;i<=n;++i){
		l[i]=lower_bound(h+1,h+t+1,l[i])-h;
		r[i]=lower_bound(h+1,h+t+1,r[i])-h;
		++ok[a[i]][l[i]];
		--ok[a[i]][r[i]];
	}
	--t;
	for(ll i=1;i<=t;++i)ok[1][i]+=ok[1][i-1],ok[2][i]+=ok[2][i-1],ok[3][i]+=ok[3][i-1];
	for(ll i=1;i<=t;++i)ok[1][i]=!ok[1][i],ok[2][i]=!ok[2][i],ok[3][i]=!ok[3][i];
	beg[2][1]=1;
	beg[1][1]=beg[3][1]=1;
	for(ll i=1;i<=t;++i){
		py(i,ok[1][i],ok[2][i],ok[3][i]);
		jy(i);
	}
	printf("%I64d\n",ed[2][t]);
	return 0;
}

