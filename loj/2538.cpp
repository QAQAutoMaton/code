/*
Author: CNYALI_LK
LANG: C++
PROG: 2538.cpp
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
int f[3005][3005],fcnt[3005],g[3005][3005],gcnt[3005],c[3005][3005],w1[3005],w2[3005];
const int p=998244353;
int sum(int a,int b){return (a+=b)>=p?a-p:a;}
int main(){
#ifdef cnyali_lk
	freopen("2538.in","r",stdin);
	freopen("2538.out","w",stdout);
#endif
	int n,m,k,t;
	read(t);
	for(int i=0;i<=3000;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)c[i][j]=sum(c[i-1][j],c[i-1][j-1]);
	}
	for(;t;--t){
		read(n,m,k);
		for(int i=1;i<=n;++i)read(w1[i]);
		sort(w1+1,w1+n+1);
		for(int i=1;i<=n;++i)read(w2[i]);
		sort(w2+1,w2+n+1);
		for(int i=1;i<=n;++i)f[0][i]=0;
		f[0][n+1]=1;
		for(int i=1;i<=k-1;++i){
			f[i][n+1]=0;
			fcnt[i-1]=f[i-1][n+1];
			for(int j=n;j;--j){
				f[i][j]=(ll)fcnt[i-1]*w1[j]%p;	
				fcnt[i-1]=sum(fcnt[i-1],f[i-1][j]);
			}
		}
		fcnt[k-1]=f[k-1][n+1];
		for(int i=1;i<=n;++i)fcnt[k-1]=sum(fcnt[k-1],f[k-1][i]);
		for(int i=k;i<=m;++i){
			fcnt[i]=0;

			for(int j=1;j<=n+1;++j){
				f[i][j]=(ll)f[k-1][j]*c[j-1][i-k+1]%p;
				fcnt[i]=sum(fcnt[i],f[i][j]);
			}
		}
		for(int i=1;i<=n;++i)g[k-1][i]=w2[i];
		
		for(int i=k-2;~i;--i){
			gcnt[i+1]=0;
			for(int j=n;j;--j){
				g[i][j]=sum(gcnt[i+1],(ll)w2[j]*c[n-j][k-i-1]%p);
				gcnt[i+1]=sum(gcnt[i+1],g[i+1][j]);
			}
		}
		for(int i=1;i<=n;++i)gcnt[0]=sum(gcnt[0],f[1][i]);
		for(int i=k;i<=m;++i){
			gcnt[i]=0;
			for(int j=1;j<=n;++j){
				g[i][j]=(ll)g[k-1][j]*c[j-1][m-i-1]%p;	
				gcnt[i]=sum(gcnt[i],g[i][j]);
			}
		}
		for(int i=0;i<k;++i){
			gcnt[i]=0;
			for(int j=1;j<=n;++j){
				g[i][j]=(ll)g[i][j]*c[j-1][m-k]%p;
				gcnt[i]=sum(gcnt[i],g[i][j]);
			}
		}	
		int ans=0;
		for(int i=0;i<=m;++i){
//			printf("%d,%d\n",fcnt[i],gcnt[i]);
			ans=sum(ans,(ll)fcnt[i]*gcnt[i]%p);
		}
		printf("%d\n",ans);
	}
	return 0;
}

