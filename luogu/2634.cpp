/*
Author: CNYALI_LK
LANG: C++
PROG: 2634.cpp
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
int a,b;
int beg[20005],to[40005],lst[40005],w[40005],e;
void add(int u,int v,int c){
	to[++e]=v;lst[e]=beg[u];beg[u]=e;w[e]=c;
}
int vis[20005],rt,siz[20005],rtw,sz;
int s1[3],s2[3];
void dfs_size(int x,int f){
	siz[x]=1;
	for(int i=beg[x];i;i=lst[i])if(to[i]!=f && !vis[to[i]]){
		dfs_size(to[i],x);
		siz[x]+=siz[to[i]];
	}
}
void dfs_rt(int x,int f){
	int mx=sz-siz[x];
	for(int i=beg[x];i;i=lst[i])if(to[i]!=f && !vis[to[i]]){
		chkmax(mx,siz[to[i]]);
		dfs_rt(to[i],x);
	}
	if(chkmin(rtw,mx))rt=x;
}
void dfs1(int x,int c,int f){
	++s2[c];
	for(int i=beg[x];i;i=lst[i])if(to[i]!=f && !vis[to[i]]){
		dfs1(to[i],(c+w[i])%3,x);
	}
}

void dfs(int x){
	dfs_size(x,0);
	sz=siz[x];
	rt=x;
	rtw=inf;
	dfs_rt(x,0);
	x=rt;
	s1[0]=1;s1[1]=s1[2]=0;
	vis[x]=1;
	for(int i=beg[x];i;i=lst[i])if(!vis[to[i]]){
		s2[0]=s2[1]=s2[2]=0;
		dfs1(to[i],w[i],x);
		a+=s1[0]*s2[0]+s1[1]*s2[2]+s1[2]*s2[1];
		s1[0]+=s2[0];s1[1]+=s2[1];s1[2]+=s2[2];
	}
	for(int i=beg[x];i;i=lst[i])if(!vis[to[i]])dfs(to[i]);
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
#ifdef cnyali_lk
	freopen("2634.in","r",stdin);
	freopen("2634.out","w",stdout);
#endif
	int n,u,v,w;	
	read(n);
	for(int i=1;i<n;++i){
		read(u,v,w);	
		w%=3;
		add(u,v,w);
		add(v,u,w);
	}
	b=n*n,a=0;
	dfs(1);
	a=a*2+n;
	int c=gcd(a,b);
	a/=c;b/=c;
	printf("%d/%d\n",a,b);
	return 0;
}

