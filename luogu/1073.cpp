/*
Author: CNYALI_LK
LANG: C++
PROG: 1073.cpp
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
struct graph{ int beg[100005],to[1000005],lst[1000005],e;
	void add(int u,int v){to[++e]=v;lst[e]=beg[u];beg[u]=e;}
};
graph a,st,ts,dl;
int w[100005],mn[100005],mx[100005];
int dfn[100005],low[100005],stk[100005],ins[100005],top,t,c,bel[100005],ans,n,m,in[100005],out[100005];
int ok[100005];
void dfs(int x){
	dfn[x]=low[x]=++t;
	ins[stk[++top]=x]=1;
	for(int i=a.beg[x];i;i=a.lst[i])if(!dfn[a.to[i]]){
		dfs(a.to[i]);
		chkmin(low[x],low[a.to[i]]);
	}
	else if(ins[a.to[i]])chkmin(low[x],dfn[a.to[i]]);
	if(dfn[x]==low[x]){
		stk[top+1]=-1;
		++c;
		mx[c]=-inf;
		mn[c]=inf;
		while(stk[top+1]!=x){
			bel[stk[top]]=c;
			ins[stk[top]]=0;
			chkmax(mx[c],w[stk[top]]);
			chkmin(mn[c],w[stk[top]]);
			--top;
		}
	}
}
void DFS(int s,int t){
	if(s==t)ok[s]=1;
	if(~ok[s])return;
	ok[s]=0;
	for(int i=dl.beg[s];i;i=dl.lst[i]){
		DFS(dl.to[i],t);
		if(ok[dl.to[i]]){
			ok[s]=1;
			st.add(s,dl.to[i]);
			ts.add(dl.to[i],s);
			
			++in[dl.to[i]];
			++out[s];
		}
	}
}
void sd(){
	for(int x=1;x<=n;++x)if(bel[x]){
		for(int i=a.beg[x];i;i=a.lst[i])if(bel[x]!=bel[a.to[i]]){
			dl.add(bel[x],bel[a.to[i]]);
		}
	}
	for(int i=1;i<=c;++i)ok[i]=-1;
	DFS(bel[1],bel[n]);
} 
void topsort1(int x){
	for(int i=st.beg[x];i;i=st.lst[i]){
		chkmin(mn[st.to[i]],mn[x]);
		if(!--in[st.to[i]])topsort1(st.to[i]);
	}
}
void topsort2(int x){
	for(int i=ts.beg[x];i;i=ts.lst[i]){
		chkmax(mx[ts.to[i]],mx[x]);
		if(!--out[ts.to[i]])topsort2(ts.to[i]);
	}
}
int main(){
#ifdef cnyali_lk
	freopen("1073.in","r",stdin);
	freopen("1073.out","w",stdout);
#endif
	int x,y,z;
	read(n,m);
	for(int i=1;i<=n;++i)read(w[i]);
	for(int i=1;i<=m;++i){
		read(x,y,z);	
		a.add(x,y);
		if(z^1)a.add(y,x);
	}
	dfs(1);
	sd();
	topsort1(bel[1]);
	topsort2(bel[n]);
	for(int i=1;i<=c;++i)if(ok[i])chkmax(ans,mx[i]-mn[i]);
	write(ans,'\n');
	return 0;
}

