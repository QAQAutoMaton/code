/*
Author: CNYALI_LK
LANG: C++
PROG: 1312.cpp
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
const int inf=0x3f3f3f3f;
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
	inline int read (int &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline int read (char &x) {
		x=gc();
		return 1;
	}
	inline int read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		return 1;
	}
	template<typename A,typename ...B>
	inline int read(A &x,B &...y){
		return read(x)+read(y...);
	}
	// print a signed integer
	inline void write (int x) {
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
struct game{
	int a[5][7],rm[5][7];
	int *operator[](int x){return a[x];}
	int Judge(){
		for(int i=0,j,k;i<5;++i){
			for(j=0,k=0;j<7;++j){
				if(a[i][j]){a[i][k]=a[i][j];++k;}
			}
			for(;k<7;++k)a[i][k]=0;
		}
		for(int i=0;i<3;++i)for(int j=0;j<7;++j)if(a[i][j]&&a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j])rm[i][j]=rm[i+1][j]=rm[i+2][j]=1;
		for(int i=0;i<5;++i)for(int j=0;j<5;++j)if(a[i][j]&&a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2])rm[i][j]=rm[i][j+1]=rm[i][j+2]=1;
		int c=0;
		for(int i=0;i<5;++i)for(int j=0;j<7;++j)if(rm[i][j])a[i][j]=rm[i][j]=0,c=1;
		return c;
	}
	void mv(int x,int y,int z){
		swap(a[x][y],a[x+z][y]);
		while(Judge());
	}
	int chk(){
		for(int i=0;i<5;++i)for(int j=0;j<7;++j){
			if(a[i][j])return 0;
		}
		return 1;
	}
};
game f[6];
int stx[6],sty[6],stfx[6],n;
void dfs(int x){
	if(x==n){
		if(f[x].chk()){
			for(int i=0;i<n;++i)write(stx[i],' ',sty[i],' ',stfx[i],'\n');
			exit(0);
		}
		return;
	}
	for(int i=0;i<5;++i)for(int j=0;j<7;++j)if(f[x][i][j]){
		stx[x]=i;sty[x]=j;
		if(i-4){stfx[x]=1;f[x+1]=f[x];f[x+1].mv(i,j,1);dfs(x+1);}
		if(i && !f[x][i-1][j]){stfx[x]=-1;f[x+1]=f[x];f[x+1].mv(i,j,-1);dfs(x+1);}
	}	
}
int main(){
#ifdef cnyali_lk
	freopen("1312.in","r",stdin);
	freopen("1312.out","w",stdout);
#endif
	read(n);
	for(int i=0,j,x;i<5;++i){
		for(j=0,read(x);x;++j,read(x))f[0][i][j]=x;
	}
	dfs(0);
	write("-1\n");
	return 0;
}

