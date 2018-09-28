/*
Author: CNYALI_LK
LANG: C++
PROG: 3648.cpp
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
//typedef long long ll;
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
ll a[102423],s[102423],f[102423],g[102423],n,mn[102423],mx[102423];
vector<ll> lst[102423];
pii q[102423],*l,*r;
void Top(ll w,ll bt){
	while(l<r && ((l+1)->y-l->y)<w*(s[(l+1)->x]-s[l->x]))++l;
	f[bt]=s[l->x]*w-l->y;
	mn[bt]=mn[l->x]+1;
	lst[bt].clear();
	while(l<r && ((l+1)->y-l->y)==w*(s[(l+1)->x]-s[l->x])){
		lst[bt].push_back(l->x);
		++l;
	}
	mx[bt]=mx[l->x]+1;
	lst[bt].push_back(l->x);
} 
void Push(pii a){
	while(l<r && (a.y-r->y)*(s[a.x]-s[(r-1)->x])<(a.y-(r-1)->y)*(s[a.x]-s[r->x]))--r;
	*(++r)=a;
}
ll dp(ll w){
	l=r=q;
	pii *Xans;
	for(ll i=1;i<=n;++i){
		if(!a[i]){
			mn[i]=mn[i-1];
			if(!w){
				mx[i]=mx[i-1]+1;
				lst[i].clear();
				lst[i].push_back(i-1);
			}
			else{
				mx[i]=mx[i-1];
				lst[i].clear();
			}
			f[i]=f[i-1];
		}else{
			Push(make_pair(i-1,s[i-1]*s[i-1]-f[i-1]));
			Top(s[i],i);
			f[i]-=w;
		}
	}
	return mn[n];
}
void Out(ll x,ll times,ll out){
	while(x && !a[x] && mx[x-1]>=times)--x;
	if(!x)return;
	--times;
	for(auto i:lst[x]){
		if(mn[i]<=times && times<=mx[i]){
			Out(i,times,1);break;
		}
	}
	if(out)printf("%lld ",x);
}
int main(){
#ifdef cnyali_lk
	freopen("3648.in","r",stdin);
	freopen("3648.out","w",stdout);
#endif
	ll k,l,r,mid;
	n=read();
	k=read()+1;
	for(ll i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}//*
	l=0,r=1e18;
	while(l<=r){
		mid=(l+r)>>1;	
		if(dp(mid)>k)l=mid+1;
		else r=mid-1;
	}
	//*/
	mid=r+1;
	dp(mid);
	printf("%lld\n",f[n]+mid*k);
	Out(n,k,0);
	putchar('\n');
	return 0;
}

