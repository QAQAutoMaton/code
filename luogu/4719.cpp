/*
Author: CNYALI_LK
LANG: C++
PROG: 4719.cpp
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
typedef int ll;
typedef pair<ll,ll> pii;
const ll inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
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
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline void read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}

	inline void read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		x=gc();
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
	}
	template<typename A,typename ...B>
	inline void read(A &x,B &...y){
		read(x);read(y...);
	}
	// prll a signed lleger
	inline void write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}

	inline void write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void write (char x) {
		putc(x);
	}
	inline void write(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void write(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
	inline void write(A x,B ...y){
		write(x);write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
vector<ll> to[100005];
ll w[100005],q[100005],*l,*r,fa[100005],dfn[100005],siz[100005],hvy[100005],t,is[100005],n; 
ll bel[100005],top[100005],lst[100005]; 
ll f[100005][2],g[100005][2];
void init(){
	for(*(l=r=q+1)=1;l<=r;++l)for(auto i:to[*l])if(i!=fa[*l])fa[*(++r)=i]=*l;
	for(;r>q;--r){++siz[*r];siz[fa[*r]]+=siz[*r];if(siz[*r]>siz[hvy[fa[*r]]])hvy[fa[*r]]=*r;}
	top[0]=1;	
	t=0;
	for(*(l=r=q)=1;l<=r;){
		is[dfn[*l]=++t]=*l;
		lst[bel[*l]=l-q]=*l;
		for(auto i:to[*l])if(i!=fa[*l] && i!=hvy[*l]){
			*(++r)=i;
			top[r-q]=i;
		}
		if(hvy[*l])*l=hvy[*l];
		else ++l;
	}
	for(ll i=1;i<=n;++i)f[i][0]=f[i][1]=g[i][0]=g[i][1]=0;
	for(r=is+t;r>is;--r){
		f[*r][1]+=w[*r];	
		g[*r][1]+=w[*r];
		if(hvy[fa[*r]]!=*r){
			f[fa[*r]][0]+=max(g[*r][0],g[*r][1]);
			f[fa[*r]][1]+=g[*r][0];
		}
		g[fa[*r]][0]+=max(g[*r][0],g[*r][1]);
		g[fa[*r]][1]+=g[*r][0];
	}
}
struct matrix{
	ll a[2][2];
	matrix(ll x00=0,ll x01=0,ll x10=0,ll x11=0){a[0][0]=x00;a[0][1]=x01;a[1][0]=x10;a[1][1]=x11;}
	ll *operator [](ll b){return a[b];}
	matrix operator *(matrix b){
		matrix c;
		for(ll i=0;i<2;++i)for(ll j=0;j<2;++j){
			c[i][j]=-inf;
			for(ll k=0;k<2;++k)chkmax(c[i][j],a[i][k]+b[k][j]);
		}
		return c;
	}
};
struct smt{
	ll ls,rs;
	smt *l,*r;
	matrix sum;
#define push_up sum=l->sum*r->sum;
	smt(ll la,ll ra){
		ls=la;rs=ra;
		if(ls==rs){
			sum=matrix(f[ls[is]][0],f[ls[is]][0],f[ls[is]][1],-inf);
			l=r=0;
		}
		else{
			ll mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
			push_up;
		}
	}
	matrix query(ll la,ll ra){
		if(la<=ls && rs<=ra)return sum;
		if(ra<=l->rs)return l->query(la,ra);
		if(la>=r->ls)return r->query(la,ra);
		return l->query(la,ra)*r->query(la,ra);
	}
	void reset(ll x){
		if(ls==rs){sum=matrix(f[ls[is]][0],f[ls[is]][0],f[ls[is]][1],-inf);return;}
		if(x<=l->rs)l->reset(x);
		else r->reset(x);
		push_up;
	}
};
smt *rt;
pii query(ll x){
	ll l=x[dfn],r=x[bel][lst][dfn];
	matrix ans=matrix(f[is[l]][0],f[is[l]][0],f[is[l]][1],-inf);
	while(++l<=r){
		ans=ans*matrix(f[is[l]][0],f[is[l]][0],f[is[l]][1],-inf);
	}	
	return make_pair(ans[0][0],ans[1][0]);
} 
void update(ll x,ll y){
	ll old=w[x];
	pii oldw,neww;
	w[x]=y;
	oldw=query(x);
	g[x][0]=oldw.x;
	g[x][1]=oldw.y;
	f[x][1]+=y-old;
	rt->reset(x);
	for(;x;x=fa[x]){
		x=x[bel][top];
		oldw=make_pair(g[x][0],g[x][1]);	
		neww=query(x);	
		g[x][0]=neww.x;
		g[x][1]=neww.y;
		f[fa[x]][0]+=max(neww.x,neww.y)-max(oldw.x,oldw.y);
		f[fa[x]][1]+=neww.x-oldw.x;
		if(fa[x])rt->reset(fa[x]);
	}
}
ll getmax(pii a){return max(a.x,a.y);}
int main(){
#ifdef cnyali_lk
	freopen("4719.in","r",stdin);
	freopen("4719.out","w",stdout); 
#endif
	ll m,u,v,x,y;	
	read(n,m);
	for(ll i=1;i<=n;++i){
		read(w[i]);
	}
	for(ll i=1;i<n;++i){
		read(u,v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	init();
	rt=new smt(1,n);
	int lsa=0;
	for(;m;--m){
		read(x,y);	
		x^=lsa;
		update(x,y);
		printf("%d\n",lsa=getmax(query(1)));
	}
	return 0;
}
