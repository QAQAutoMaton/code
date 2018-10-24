/*
Author: CNYALI_LK
LANG: C++
PROG: sortall.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;} template<class T>T mmax(T a,T b){return a>b?a:b;} template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
int read(){
	int s=0;
	int base=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=1;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	if(base)s=-s;
	return s;
}
const int p=1000000007;
int n,a[102423],pre[102423],pa[102423];	
int Sum(int a,int b){return (a+=b)>=p?a-p:a;}
struct BIT{
	int s[102423];
	void add(int x,int y){for(;x<=n;x+=x&-x)s[x]=Sum(s[x],y);}
	int sum(int x){int y=0;for(;x;x&=x-1)y=Sum(y,s[x]);return y;}
}bit1,bit2;
pii operator +(pii a,pii b){
	return make_pair(Sum(a.x,b.x),Sum(a.y,b.y));
}
pii o;
struct smt{
	int ls,rs;
	int cnt[4];
	smt *l,*r;
	smt(int la,int ra){
		ls=la;rs=ra;
		for(int i=0;i<4;++i)cnt[i]=0;
		l=r=0;
	}
	void add(int x,int *w){
		if(x<ls || x>rs)return;
		for(int i=0;i<4;++i)cnt[i]=Sum(cnt[i],w[i]);
		if(ls==rs)return;
		if(!l){
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
		}
		if(x<=l->rs)l->add(x,w);
		else r->add(x,w);
	}
	int sum(int la,int ra,int x){
		if(!cnt[0])return 0;
		if(la<=ls && rs<=ra)return cnt[x];	
		int s=0;
		if(la<=l->rs)s+=l->sum(la,ra,x);
		if(r->ls<=ra)s+=r->sum(la,ra,x);
		if(s>=p)s-=p;
		return s;
	}
};
struct BiT{
	smt *s[102423];
	void init(){
		for(int i=1;i<=n;++i)s[i]=new smt(1,n);
	}
#define lowbit(x) x&-x
	void add(int x,int y,int *w){
		for(;x<=n;x+=lowbit(x))s[x]->add(y,w);
	}
	int sum(int l,int r,int xl,int xr,int x){
		if(l>r||xl>xr)return 0;
		int su=0;
		--l;
		for(;l;l^=lowbit(l))su=Sum(su,p-s[l]->sum(xl,xr,x));
		for(;r;r^=lowbit(r))su=Sum(su,s[r]->sum(xl,xr,x));
		return su;
	}
}bit;
int calc(int xl,int xr,int yl,int yr){
	return Sum(bit.sum(xl+1,xr,yl,yr,1),p-(ll)xl*bit.sum(xl+1,xr,yl,yr,0)%p);
}
int v[4];
int main(){
#ifdef cnyali_lk
	freopen("sortall.in","r",stdin);
	freopen("sortall.out","w",stdout);
#endif
	n=read();
	int s=0,w,ans=0;
	bit.init();
	for(int i=1;i<=n;++i){
		a[i]=read();
		bit1.add(a[i],i-pre[a[i]]);
		s=Sum(s,(ll)Sum(i-pre[a[i]],calc(pre[a[i]],i,1,a[i]-1))*a[i]%p);
		s=Sum(s,bit.sum(pre[a[i]]+1,i,a[i]+1,n,3));
		s=Sum(s,p-(ll)bit.sum(pre[a[i]]+1,i,a[i]+1,n,2)*pre[a[i]]%p);
		ans=Sum(ans,s);
		v[0]=1;v[1]=i;v[2]=a[i];v[3]=(ll)i*a[i]%p;
		bit.add(i,a[i],v);
		if(pre[a[i]]){
			v[0]=p-1;v[1]=p-pre[a[i]];v[2]=p-a[i];v[3]=p-(ll)pre[a[i]]*a[i]%p;
			bit.add(pre[a[i]],a[i],v);
		}
		pre[a[i]]=i;
	}
	printf("%d\n",ans);
	return 0;
}

