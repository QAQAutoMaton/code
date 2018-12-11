/*
Author: CNYALI_LK
LANG: C++
PROG: 3204.cpp
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
const int mo=30031;
int fs[1025],orz[1025],t;
struct matrix{
	int a[127][127];
	int *operator [](int b){return a[b];}
	matrix operator *(matrix b){
		matrix c;
		for(int i=1;i<=t;++i)for(int j=1;j<=t;++j){
			c[i][j]=0;
			for(int k=1;k<=t;++k)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mo;
		}
		return c;
	}
	matrix operator ^(int b){
		matrix c,a=*this;	
		for(int i=1;i<=t;++i)for(int j=1;j<=t;++j)c[i][j]=i==j;
		for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
matrix a,b;
int main(){
#ifdef cnyali_lk
	freopen("3204.in","r",stdin);
	freopen("3204.out","w",stdout);
#endif

	int n,k,p;	
	read(n,k,p);
	for(int i=0;i<1<<(p-1);++i)if(__builtin_popcount(i)==k-1){
		fs[orz[i]=++t]=i;
	}
	b[orz[(1<<(k-1))-1]][1]=1;
	for(int i=1;i<=t;++i){
		int s=fs[i],o=s;	
		a[i][orz[s<<1]]=1;
		for(;o;o&=o-1){
			a[i][orz[(s^(o&-o))<<1|1]]=1;
		}
	}
	b=(a^(n-k))*b;
//	for(int i=1;i<=t;++i)for(int j=1;j<=t;++j)printf("%d%c",b[i][j],j==t?'\n':' ');
	printf("%d\n",b[orz[(1<<(k-1))-1]][1]);
	return 0;
}

