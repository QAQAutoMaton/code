/*
Author: QAQ-Automaton
LANG: C++
PROG: e.cpp
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
		while((x=gc())=='\n' || x==' '||x=='\r');
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
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
int a[105][105],f[2][105][105][105],b[105][105];
int main(){
#ifdef QAQAutoMaton 
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	int n,m,x,y;
	char c;
	read(n,m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		read(c);
		if(c=='E')x=i,y=j;
		a[i][j]=c=='o';
		b[i][j]=c=='o';
		a[i][j]+=a[i][j-1];
		b[i][j]+=b[i-1][j];
	}
	int ans=0;
	for(int xl=0,t=0;xl<x;++xl,t^=1){ 
		for(int xr=0;xr<=n-x;++xr){
			for(int yl=0;yl<y;++yl){
				for(int yr=0;yr<=m-y;++yr){
					f[t][xr][yl][yr]=0;
					if(xl)
						chkmax(f[t][xr][yl][yr],
								f[t^1][xr][yl][yr]+
								(xr>=x-xl?0:max(0,a[x-xl][min(y+yr,m-yl)]-a[x-xl][max(y-yl-1,yr)]))
							  );
					if(xr)
						chkmax(f[t][xr][yl][yr],
								f[t][xr-1][yl][yr]+
								(xl+xr>n-x?0:max(0,a[x+xr][min(y+yr,m-yl)]-a[x+xr][max(y-yl-1,yr)]))
							  );
					if(yl)
						chkmax(f[t][xr][yl][yr],
								f[t][xr][yl-1][yr]+
								(yl+yr>=y?0:max(0,b[min(x+xr,n-xl)][y-yl]-b[max(x-xl-1,xr)][y-yl]))
							  );
					if(yr)
						chkmax(f[t][xr][yl][yr],
								f[t][xr][yl][yr-1]+
								(yl+yr>m-y?0:max(0,b[min(x+xr,n-xl)][y+yr]-b[max(x-xl-1,xr)][y+yr]))
							  );
					chkmax(ans,f[t][xr][yl][yr]);	
				}
			}
		}
	}
	write(ans,'\n');
	return 0;
}

