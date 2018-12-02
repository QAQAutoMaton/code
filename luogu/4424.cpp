/*
Author: CNYALI_LK
LANG: C++
PROG: 4424.cpp
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
bool a[5005][1005];
char s[5005];
int atb[5005],bta[5005],ed[5005],value[5005];
int son[5000005][2],w[5000005],t=1,c;
int n,m,q;	
void insert(int x,int n){
	int r=1;
	for(int i=1;i<=n;++i){
		if(!son[r][a[x][i]])son[r][a[x][i]]=++t;
		r=son[r][a[x][i]];
	}
	w[r]=1;
	ed[x]=r;
}
void Orz(int x){
	if(w[x]){w[x]=++c;}	
	else{
		if(son[x][0])Orz(son[x][0]);
		if(son[x][1])Orz(son[x][1]);
	}
}
const int p=1000000007;
int mod(int a){return a>=p?a-p:a;}
int Sum(int a,int b){return a+=b,a>=p?a-p:a;}
int to(int x){
	int w=0;
	for(int i=1;i<=n;++i){
		w=mod(w<<1|a[x][i]);
	}
	return w;
}
int main(){
#ifdef cnyali_lk
	freopen("4424.in","r",stdin);
	freopen("4424.out","w",stdout);
#endif
	read(n,m,q);
	for(int i=n;i;--i){read(s+1);for(int j=1;j<=m;++j)a[j][i]=s[j]^'0';}
	for(int i=1;i<=m;++i){
		insert(i,n);
	}

	Orz(1);
	for(int i=1;i<=m;++i){
		value[w[ed[i]]]=to(i);
	}
	value[c+1]=1;
	for(int i=1;i<=n;++i)value[c+1]=mod(value[c+1]<<1);
	for(;q;--q){
		read(s+1);
		int mx=0,mn=c+1;
		for(int i=1;i<=m;++i){
			if(s[i]=='1')chkmin(mn,w[ed[i]]); else chkmax(mx,w[ed[i]]); 
		}
		if(mn<mx){write("0\n");}
		else {
			write(Sum(value[mn],p-value[mx]),'\n');
		}
	}
	
	return 0;
}

