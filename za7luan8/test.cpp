/*
Author: CNYALI_LK
LANG: C++
PROG: test.cpp
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
template<typename T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<typename T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<typename T>T sqr(T a){return a*a;}
template<typename T>T mmin(T a,T b){return a<b?a:b;}
template<typename T>T mmax(T a,T b){return a>b?a:b;}
template<typename T>T aabs(T a){return a<0?-a:a;}
template<typename T>int dcmp(T a,T b){return a>b;}
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
	inline void read (int &x) {
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
	inline void print (int x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void print (char x) {
		putc(x);
	}
	inline void print(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void print(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
	inline void print(A x,B ...y){
		print(x);print(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: print;
void work(){
	int x;
	++x;
	print(x,'!');
}
int main(){
#ifdef cnyali_lk
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif
	work();	
	work();	
	work();	
	work();	
	work();	
	int x;
	print(x,'\n');
	return 0;
}

