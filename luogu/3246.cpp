/*
Author: CNYALI_LK
LANG: C++
PROG: 3246.cpp
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
ll a[100005],lg2[100005],mn[19][100005],pre[100005],nxt[100005],fp[100005],fs[100005],ans[100005];
ll n,q,blk;	
struct query{
	ll l,r,blk,id;
};
query ask[100005];
ll cmp(query a,query b){return a.blk<b.blk||a.blk==b.blk && a.r<b.r;}
ll xmin(ll x,ll y){return a[x]<a[y]?x:y;}
void getpn(ll x){
	ll wz=x;
	for(ll i=18;~i;--i){
		if(wz>=1<<i && a[mn[i][wz-(1<<i)+1]]>=a[x])wz-=1<<i;
	}
	pre[x]=wz;
	wz=x;
	for(ll i=18;~i;--i){
		if(wz+(1<<i)<=n+1 && a[mn[i][wz]]>=a[x])wz+=1<<i;
	}
	nxt[x]=wz;
}
void getf(ll x){
	ll lst=x,now=x;
	fs[x]=0;
	while(lst){
		lst=pre[lst];	
		fs[x]+=a[now]*(now-lst);
		now=lst;
	}
	lst=x;now=x;
	fp[x]=0;
	while(lst<=n){
		lst=nxt[lst];	
		fp[x]+=a[now]*(lst-now);
		now=lst;
	}
}
ll qmin(ll l,ll r){
	ll lg=lg2[r-l+1];
	return xmin(mn[lg][l],mn[lg][r-(1<<lg)+1]);
}
ll fpre(ll l,ll r){
	ll m1n=qmin(l,r),ans=(r-m1n+1)*a[m1n],nx=nxt[l];	
	ans+=(nx-l)*a[l];
	ans+=fp[nx]-fp[m1n];
	return ans;
}
ll fsuf(ll l,ll r){
	ll m1n=qmin(l,r),ans=(m1n-l+1)*a[m1n],pr=pre[r];	
	ans+=(r-pr)*a[r];
	ans+=fs[pr]-fs[m1n];
	return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("3246.in","r",stdin);
	freopen("3246.out","w",stdout);
#endif
	read(n,q);
	blk=sqrt(n);
	for(ll i=1;i<=n;++i){read(a[i]);mn[0][i]=i;}

	for(ll i=1;i<=18;++i)for(ll j=1;j+(1<<i)-1<=n;++j)mn[i][j]=xmin(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
	for(ll i=1;i<=n;++i)getpn(i);
	for(ll i=1;i<=n;++i)getf(i);
	lg2[0]=-1;
	for(ll i=1;i<=n;++i)lg2[i]=lg2[i>>1]+1;
	for(ll i=1;i<=q;++i){
		read(ask[i].l,ask[i].r);
		ask[i].blk=ask[i].l/blk;
		ask[i].id=i;
//		for(ll j=ask[i].l;j<=ask[i].r;++j)ans[i]+=fpre(j,ask[i].r);
	}
	
	sort(ask+1,ask+q+1,cmp);
	ll l=1,r=1,Ans=fsuf(1,1);
	for(ll i=1;i<=q;++i){
		while(r<ask[i].r){++r;Ans+=fsuf(l,r);}
		while(l>ask[i].l){--l;Ans+=fpre(l,r);}
		while(r>ask[i].r){Ans-=fsuf(l,r);--r;}
		while(l<ask[i].l){Ans-=fpre(l,r);++l;}
		ans[ask[i].id]=Ans;
	}
	for(ll i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}

