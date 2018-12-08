/*
Author: CNYALI_LK
LANG: C++
PROG: 4426.cpp
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
const ll p=998244353;
ll n,m,to[400055],lst[400055],beg[100005],e,a[200005][2][2],c[100005],d[100005],del[200005],delpoll[100005];	
void add(ll u,ll v){to[++e]=v;lst[e]=beg[u];beg[u]=e;}
ll deg[100005];
ll q[100005],*l=q+1,*r=q;
ll poll[100005],w[200005][2][2],u[100005],v[100005];
int main(){
#ifdef cnyali_lk
	freopen("4426.in","r",stdin);
	freopen("4426.out","w",stdout);
#endif
	read(n,m);
	e=1;
	for(ll i=1;i<=n;++i)c[i]=d[i]=1;
	for(ll i=1;i<=m;++i){
		read(*u,*v);	
		add(*u,*v);
		add(*v,*u); 
		a[i][1][0]=a[i][0][1]=a[i][0][0]=1;
		++deg[*u];++deg[*v];
	}
	for(ll i=1;i<=n;++i){
		if(deg[i]==1)*(++r)=i;	
	}
	while(l<=r){
		if(!deg[*l])break;
		ll x=0;
		
		for(ll i=beg[*l];i;i=lst[i])if(!del[i>>1]){
			++x;
			del[i>>1]=1;
			if((--deg[to[i]])==1)*(++r)=to[i];
			if(i&1){
				c[to[i]]*=(c[*l]*a[i>>1][1][1]+d[*l]*a[i>>1][0][1])%p;
				d[to[i]]*=(c[*l]*a[i>>1][1][0]+d[*l]*a[i>>1][0][0])%p;
			}
			else{
				c[to[i]]*=(c[*l]*a[i>>1][1][1]+d[*l]*a[i>>1][1][0])%p;
				d[to[i]]*=(c[*l]*a[i>>1][0][1]+d[*l]*a[i>>1][0][0])%p;
			}
			c[to[i]]%=p;
			d[to[i]]%=p;
		}
		delpoll[*l]=1;
		++l;
	}
	for(ll i=1;i<=n;++i)if(deg[i]==2){
		ll t=0;

		for(ll j=beg[i];j;j=lst[j]){
			if(!del[j>>1]){
				poll[t]=to[j];
				w[t][0][0]=a[j>>1][0][0];
				w[t][1][1]=a[j>>1][1][1];
				w[t][1][0]=a[j>>1][1][0];
				w[t][0][1]=a[j>>1][0][1];
				if(!(j&1))swap(w[t][0][1],w[t][1][0]);
				++t;
			}	
		}		
		if(poll[0]==i || poll[1]==i)break;
		for(ll j=beg[i];j;j=lst[j]){
			if(!del[j>>1]){
				del[j>>1]=1;
				--deg[i];
				--deg[to[j]];
			}	
		}		
		add(poll[1],poll[0]);
		add(poll[0],poll[1]);
		++deg[poll[0]];
		++deg[poll[1]];
		a[e>>1][0][0]=(c[i]*w[0][1][0]%p*w[1][1][0]+d[i]*w[0][0][0]%p*w[1][0][0])%p;
		a[e>>1][0][1]=(c[i]*w[0][1][0]%p*w[1][1][1]+d[i]*w[0][0][0]%p*w[1][0][1])%p;
		a[e>>1][1][0]=(c[i]*w[0][1][1]%p*w[1][1][0]+d[i]*w[0][0][1]%p*w[1][0][0])%p;
		a[e>>1][1][1]=(c[i]*w[0][1][1]%p*w[1][1][1]+d[i]*w[0][0][1]%p*w[1][0][1])%p;
		delpoll[i]=1;
	}
	ll t=0;
	for(ll i=1;i<=n;++i)if(!delpoll[i]){poll[delpoll[i]=t]=i;++t;}
	m=e>>1;e=0;
	for(ll i=1;i<=m;++i)if(!del[i]){
		++e;
		u[e]=delpoll[to[i<<1]];
		v[e]=delpoll[to[i<<1|1]];
		w[e][0][0]=a[i][0][0];
		w[e][0][1]=a[i][0][1];
		w[e][1][0]=a[i][1][0];
		w[e][1][1]=a[i][1][1];
	}
	ll ans=0,s;
	for(ll i=0;i<1<<t;++i){
		s=1;
		for(ll j=0;j<t;++j){
			s=s*((i&(1<<j))?c[poll[j]]:d[poll[j]])%p;

		}
		for(ll j=1;j<=e;++j)s=s*w[j][!!(i&(1<<u[j]))][!!(i&(1<<v[j]))]%p;
		ans=(ans+s)%p;
	}
	
	printf("%lld\n",ans);
	return 0;
}

