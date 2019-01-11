/*
Author: CNYALI_LK
LANG: C++
PROG: 2540.cpp
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
const int p=998244353;
int sum(int a,int b){return (a+=b)>=p?a-p:a;}
int n,m,u,v,mx,a[25],f[25][1<<20],A[25][25],deg[25],fulls;
bool vis[25][1<<20];
void DFS(int x,int y){
	if(vis[x][y])return;
	vis[x][y]=1;
	if(y+1 == 1<<n){f[x][y]=x==mx;return;}
	for(int i=0;i<n;++i)if(!(y&1<<i)){
		int xy=y|(1<<i)|a[i];
		DFS(x+1,xy);	
		f[x][y]=sum(f[x][y],(ll)f[x+1][xy]*A[n-__builtin_popcount(y)-1][__builtin_popcount(a[i]&(fulls^y))]%p);
	}
}
int fpm(int a,int b){int c=1;for(;b;b>>=1,a=(ll)a*a%p)if(b&1)c=(ll)c*a%p;return c;}
int main(){
#ifdef cnyali_lk
	freopen("2540.in","r",stdin);
	freopen("2540.out","w",stdout);
#endif
	read(n,m);
	for(int i=0;i<=n;++i){
		A[i][0]=1;
		for(int j=1;j<=i;++j)A[i][j]=(ll)A[i][j-1]*(i-j+1)%p; 
	}
	fulls=(1<<n)-1;
	for(;m;--m){
		read(u,v);
		--u;--v;
		a[u]|=1<<v;
		a[v]|=1<<u;
		++deg[u];
		++deg[v];
	}
	mx=0;
	int s,ok;
	for(int i=1;i<1<<n;++i){
		ok=1,s=__builtin_popcount(i);
		if(s<mx)continue;
		for(int j=0;j<n;++j)if((i&(1<<j)) && (i&a[j])){ok=0;break;}
		if(ok)mx=s;
	}
	DFS(0,0);
	s=1;
	for(int i=1;i<=n;++i)s=(ll)s*i%p;
	write((ll)f[0][0]*fpm(s,p-2)%p,'\n');
	return 0;
}

