/*
Author: CNYALI_LK
LANG: C++
PROG: 2542.cpp
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
typedef long long ll;
typedef pair<int,int> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
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
	// print a signed integer
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
int fa[21],fb[21],deg[21],f[1<<18],inv[21];
vector<int> to[21];
int n,q,x,u,v,se;
const int p=998244353;
int sum(int a,int b){return (a+=b)>=p?a-p:a;}
int fpm(int a,int b){int c=1;for(;b;b>>=1,a=(ll)a*a%p)if(b&1)c=(ll)c*a%p;return c;}
void dfs(int x,int f){
//	printf("%d!\n",x);
	if((1<<(x-1)) & se){fa[x]=fb[x]=0;return;}
	fa[x]=0;
	fb[x]=0;
	int stf=0; 
	for(auto i:to[x])if(i!=f){
		dfs(i,x);
		stf=sum(stf,fa[i]);
		fb[x]=sum(fb[x],fb[i]);
	}
	stf=fpm(sum(1,p-(ll)stf*inv[deg[x]]%p),p-2);
	fb[x]=((ll)fb[x]*inv[deg[x]]+1)%p*stf%p;
	fa[x]=(ll)inv[deg[x]]*stf%p;
}
void calc(){
	dfs(x,0);	
	f[se]=fb[x];
	if(!(__builtin_popcount(se)&1))f[se]=(p-f[se])%p;
}
void subset(){
	for(int i=1;i<1<<n;i<<=1){
		for(int j=0;j<1<<n;j+=i+i){
			for(int k=0;k<i;++k)f[j+k+i]=sum(f[j+k+i],f[j+k]);
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("2542.in","r",stdin);
	freopen("2542.out","w",stdout);
#endif
	read(n,q,x);
	for(int i=1;i<n;++i){
		read(u,v);	
		++deg[u];++deg[v];
		to[u].push_back(v);
		to[v].push_back(u);
	}
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=(ll)(p-p/i)*inv[p%i]%p;
	for(se=1;se<1<<n;++se){
		calc();
	}
	subset();
	for(;q;--q){
		read(u);
		v=0;
		for(;u;--u){read(x);v|=1<<(x-1);}
		printf("%d\n",f[v]);
	}
	return 0;
}

