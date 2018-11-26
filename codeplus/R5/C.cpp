/*
Author: CNYALI_LK
LANG: C++
PROG: C.cpp
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
pii e[2500005];
vector<int> son[1000005];
int fa[1000005],siz[1000005];
int f[1000005];
void dfs(int x,int fa){
	f[x]=fa;
	siz[x]=1;
	for(auto i:son[x])if(i!=fa){
		dfs(i,x);
		siz[x]+=siz[i];
	}
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
#ifdef cnyali_lk
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,m,q;
	read(n,m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		read(e[i].x,e[i].y);
		if(find(e[i].x)==find(e[i].y))continue;
		fa[find(e[i].x)]=find(e[i].y);
		son[e[i].x].push_back(e[i].y);
		son[e[i].y].push_back(e[i].x);
	}
	dfs(1,0);
	read(q);	
	for(;q;--q){
		int cnt,ans=0,id,u,v;
		read(cnt);
		for(;cnt;--cnt){
			read(id);
			u=e[abs(id)].x;	
			v=e[abs(id)].y;
			if(id<0)swap(u,v);
			if(f[u]==v)ans-=siz[u];
			if(f[v]==u)ans+=siz[v];
		}
		if(ans<0)ans+=n;
		printf("%d\n",ans);
	}
	return 0;
}

