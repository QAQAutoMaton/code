/*
Author: CNYALI_LK
LANG: C++
PROG: 3960.cpp
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
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
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
ll ls[3000005],rs[3000005],son[3000005][2],fa[3000005],t,rt[300005],rrt,siz[3000005];
ll generate(ll la,ll ra,ll m){
	ll r=++t,mid=(la+ra)>>1;
	siz[r]=ra-la+1;
	ls[r]=rs[r]=mid*m;
	if(la<mid)fa[son[r][0]=generate(la,mid-1,m)]=r;
	if(mid<ra)fa[son[r][1]=generate(mid+1,ra,m)]=r;
	return r;
}
#define push_up(x) siz[x]=siz[son[x][0]]+siz[son[x][1]]+(rs[x]-ls[x]+1)
void rotate(ll x){
	ll f=fa[x],g=fa[f],fx=son[f][1]==x;
	son[fa[x]=g][son[g][1]==f]=x;
	fa[f]=x;
	fa[son[f][fx]=son[x][fx^1]]=f;
	son[x][fx^1]=f;
	push_up(f);
	push_up(x);
}
void splay(ll x){
	while(fa[x]){
		ll f=fa[x]; if(fa[f])if((son[fa[f]][1]==f)==(son[f][1]==x))rotate(f);
		else rotate(x);
		rotate(x);
	}
}
ll Cut(ll &rt,ll w){
	while(rt){
		if(w<=siz[son[rt][0]]){rt=son[rt][0];}
		else{
			w-=siz[son[rt][0]];
			if(w<=rs[rt]-ls[rt]+1){splay(rt);break;}else{w-=rs[rt]-ls[rt]+1;rt=son[rt][1];}
		}
	}
	if(ls[rt]==rs[rt]){
		ll x=rt;
		fa[son[x][0]]=0;
		fa[son[x][1]]=0; 
		if(!son[x][0]){rt=son[x][1];son[x][1]=0;push_up(x);return x;}
		rt=son[x][0];
		while(son[rt][1])rt=son[rt][1];
		splay(rt);
		fa[son[rt][1]=son[x][1]]=rt;
		push_up(rt);
		son[x][0]=son[x][1]=0;
		push_up(x);
		return x;
	}
	else{
		ll x=++t; 
		ls[x]=rs[x]=ls[rt]+w-1;
		siz[x]=1;
		if(ls[x]==ls[rt]){
			++ls[rt];
			--siz[rt];
		}
		else if(rs[x]==rs[rt]){
			--rs[rt];
			--siz[rt];
		}
		else{
			ll y=++t;
			fa[son[y][1]=son[rt][1]]=y;
			rs[y]=rs[rt];
			ls[y]=rs[x]+1;
			rs[rt]=ls[x]-1;
			fa[son[rt][1]=y]=rt;
			push_up(y);
			push_up(rt);
		}
		
		return x;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("3960.in","r",stdin);
	freopen("3960.out","w",stdout);
#endif
	ll n,m,q;
	read(n,m,q);
	for(ll i=1;i<=n;++i){
		rt[i]=++t;
		ls[t]=(i-1)*m+1;
		rs[t]=i*m-1;
		siz[t]=m-1;
	}
	rrt=generate(1,n,m);
	ll x,y,r0,r1;
	for(;q;--q){
		read(x,y);	
		if(y==m){
			r0=Cut(rrt,x);
			write(ls[r0],'\n');
			fa[son[r0][0]=rrt]=r0;
			push_up(r0);
			rrt=r0;
		}
		else{

			r0=Cut(rt[x],y);
			write(ls[r0],'\n');
			r1=Cut(rrt,x);
			fa[son[r1][0]=rt[x]]=r1;
			fa[son[r0][0]=rrt]=r0;
			push_up(r1);
			push_up(r0);
			rt[x]=r1;
			rrt=r0;
		}
	}
	return 0;
}

