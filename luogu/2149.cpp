/*
Author: CNYALI_LK
LANG: C++
PROG: 2149.cpp
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
int w[1505][1505],dis1[1505],dis2[1505],dis3[1505],dis4[1505],n,vis[1505];
void dijkstra(int s,int *dis){
	for(int i=1;i<=n;++i)dis[i]=inf,vis[i]=0;	
	dis[s]=0;
	int x,y;
	for(int t=n;t;--t){
		x=inf,y=0;
		for(int i=1;i<=n;++i)if(!vis[i] && chkmin(x,dis[i]))y=i;
		if(!y)break;
		vis[y]=1;
		for(int i=1;i<=n;++i)chkmin(dis[i],x+w[y][i]);
	}
}
int e[1505][1505],in[1505],f[1505],ans;
void add(int u,int v){
	printf("...%d %d\n",u,v);
	e[u][v]=1;
	++in[v];
}
void topsort(int u){
	chkmax(ans,f[u]);
	for(int i=1;i<=n;++i)if(e[u][i]){chkmax(f[i],f[u]+w[u][i]);if(!--in[i])topsort(i);}
}
int main(){
#ifdef cnyali_lk
	freopen("2149.in","r",stdin);
	freopen("2149.out","w",stdout);
#endif
	int u,v,c,s1,t1,s2,t2,m; 
	read(n,m);
	read(s1,t1,s2,t2);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)w[i][j]=(i!=j)*inf;
	for(int i=1;i<=m;++i){
		read(u,v,c);	
		chkmin(w[u][v],c);
		chkmin(w[v][u],c);
	}
	dijkstra(s1,dis1);
	dijkstra(t1,dis2);
	dijkstra(s2,dis3);
	dijkstra(t2,dis4);
	for(int i=1;i<=n;++i)printf("%d %d %d %d\n",dis1[i],dis2[i],dis3[i],dis4[i]);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j
			&& (dis1[i]+w[i][j]==dis1[j]&&dis2[j]+w[i][j]==dis2[i] || dis1[j]+w[i][j]==dis1[i]&&dis2[i]+w[i][j]==dis2[j])
			&& (dis3[i]+w[i][j]==dis3[j]&&dis4[j]+w[i][j]==dis4[i])
			)
		add(i,j);
	else printf("[%d-%d]%d%d%d%d%d\n",i,j,i!=j,dis1[i]+w[i][j]==dis1[j],dis2[j]+w[i][j]==dis2[i],dis3[i]+w[i][j]==dis3[j],dis4[j]+w[i][j]==dis4[i]
			);
	for(int i=1;i<=n;++i)if(!in[i])topsort(i);
	printf("%d\n",ans);
	return 0;
}

