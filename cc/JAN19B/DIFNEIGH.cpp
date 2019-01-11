/*
Author: QAQ-Automaton
LANG: C++
PROG: DIFNEIGH.cpp
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
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// print a signed integer
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
int a[105][105];
int main(){
#ifdef QAQAutoMaton 
	freopen("DIFNEIGH.in","r",stdin);
	freopen("DIFNEIGH.out","w",stdout);
#endif
	int t,n,m;
	a[1][1]=1;
	a[3][1]=2;a[2][2]=3;a[1][3]=4;
	a[5][1]=3;a[4][2]=4;a[3][3]=1;a[2][4]=2;a[1][5]=3;
	for(int i=8;i<=104;i+=2){
		for(int j=1;j<i;++j){
			if(j<=i>>1)a[i-j][j]=a[i-j-3][j+1];
			else a[i-j][j]=a[i-j+1][j-3];
		}
	}
	read(t);
	for(;t;--t){
		read(n,m);	
		if(n*m<=2){
			write("1\n");
			for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)write(1,j==m?'\n':' ');
		}
		else if(n==2 && m==2){
			write("2\n1 1\n2 2\n");
		}
		else if(n==1 || m==1){
			write("2\n");
			for(int i=0;i<n;++i)for(int j=0;j<m;++j)
				write(!!((i&2) ^ (j&2))+1,j==m-1?'\n':' ');
		}
		else if(n<3 || m<3){
			write("3\n");
			if(n==2){
				for(int i=0;i<m;++i)write(i%3+1,i==m-1?'\n':' ');
				for(int i=0;i<m;++i)write(i%3+1,i==m-1?'\n':' ');
			}
			else{
				for(int i=0;i<n;++i)write(i%3+1,' ',i%3+1,'\n');
			}
		}
		else{
			write(4,'\n');
			for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)write(((i&1)^(j&1)?a[i+1][j]:a[i][j]),j==m?'\n':' ');
		}	

	}

	return 0;
}

