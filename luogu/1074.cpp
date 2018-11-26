/*
Author: CNYALI_LK
LANG: C++
PROG: 1074.cpp
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
int score[81]={
	6,6,6,6,6,6,6,6,6,
	6,7,7,7,7,7,7,7,6,
	6,7,8,8,8,8,8,7,6,
	6,7,8,9,9,9,8,7,6,
	6,7,8,9,10,9,8,7,6,
	6,7,8,9,9,9,8,7,6,
	6,7,8,8,8,8,8,7,6,
	6,7,7,7,7,7,7,7,6,
	6,6,6,6,6,6,6,6,6
};
int blk[81]={
	0,0,0,1,1,1,2,2,2,
	0,0,0,1,1,1,2,2,2,
	0,0,0,1,1,1,2,2,2,
	3,3,3,4,4,4,5,5,5,
	3,3,3,4,4,4,5,5,5,
	3,3,3,4,4,4,5,5,5,
	6,6,6,7,7,7,8,8,8,
	6,6,6,7,7,7,8,8,8,
	6,6,6,7,7,7,8,8,8
};
int a[81],nxt[81];
int x[9],y[9],z[9],ans,w,cnt[9],bt[9];
void dfs(int b){
	if(b==81){
		chkmax(ans,w);
		return;
	}
	int s=x[b/9]&y[b%9]&z[blk[b]],l; 
	while(s){
		l=s&-s;
		x[b/9]^=l;
		y[b%9]^=l;
		z[blk[b]]^=l;
		w+=(__builtin_ctz(l)+1)*score[b];
		dfs(nxt[b]);
		w-=(__builtin_ctz(l)+1)*score[b];
		x[b/9]^=l;
		y[b%9]^=l;
		z[blk[b]]^=l;
		s^=l;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("1074.in","r",stdin);
	freopen("1074.out","w",stdout); 
#endif
	for(int i=0;i<9;++i)x[i]=y[i]=z[i]=511;
	for(int i=0;i<81;++i){
		read(a[i]);
		w+=a[i]*score[i];
		--a[i];
		if(~a[i]){
			++cnt[i/9];

			x[i/9]^=1<<a[i];
			y[i%9]^=1<<a[i];
			z[blk[i]]^=1<<a[i];
		}
	}
	for(int i=0;i<9;++i)bt[i]=i;
	sort(bt,bt+9,cmp_a<cnt>);
	int lst=81;
	for(int i=0;i<9;++i)for(int j=8;~j;--j){
		nxt[bt[i]*9+j]=lst;
		if(!~a[bt[i]*9+j])lst=bt[i]*9+j;
	}
	ans=-1;
	dfs(lst);
	printf("%d\n",ans);
	return 0;
}

