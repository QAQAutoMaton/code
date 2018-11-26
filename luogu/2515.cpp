/*
Author: CNYALI_LK
LANG: C++
PROG: 2515.cpp
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
int bel[105],w[105],v[105],pre[105],f[105][505],fa[105],vis[105],n,m;
int t;
vector<int> son[105];
void findC(int x){
	bel[x]=x;
	++t;
	while(!vis[x]){vis[x]=t;x=pre[x];}
	if(vis[x]==t){
		int r=x;
		for(x=pre[x];x!=r;x=pre[x]){bel[x]=r;w[r]+=w[x];v[r]+=v[x];}
	}
}
void dfs(int x){
	for(auto i:son[x])if(w[i]<=m){
		for(int j=0;j<w[i];++j)f[i][j]=-inf;
		for(int j=w[i];j<=m;++j)f[i][j]=f[x][j-w[i]]+v[i];
		dfs(i);
		for(int j=0;j<=m;++j)chkmax(f[x][j],f[i][j]);
	}
}
int main(){
#ifdef cnyali_lk
	freopen("2515.in","r",stdin);
	freopen("2515.out","w",stdout);
#endif
	read(n,m);
	for(int i=1;i<=n;++i)read(w[i]);
	for(int i=1;i<=n;++i)read(v[i]);
	for(int i=1;i<=n;++i)read(pre[i]);
	vis[0]=1;
	for(int i=1;i<=n;++i)bel[i]=i;
	t=1;
	for(int i=1;i<=n;++i)if(!vis[i])findC(i);
	for(int i=1;i<=n;++i)if(bel[i]==i){
		if(bel[pre[i]]!=i)
			fa[i]=bel[pre[i]];
		else 
			fa[i]=0;
		son[fa[i]].push_back(i);
	}
	dfs(0);
	write(f[0][m],'\n');
	return 0;
}

