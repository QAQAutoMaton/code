/*
Author: CNYALI_LK
LANG: C++
PROG: 1155.cpp
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
int a[1005],mn[1005];
int col[1005];
vector<int> to[1005];
void dfs(int x,int c){
	if(~col[x]){if(col[x]!=c){write("0\n");exit(0);}return;}
	col[x]=c;
	for(int i=0,t=to[x].size();i<t;++i)dfs(to[x][i],c^1);
}
int s[2][1005],top[2],pos=1;
void push(int x,int y){
	s[x][++top[x]]=y;
	write(char('a'+2*x),' ');
} 
int pop(int x){
	if(s[x][top[x]]==pos){
		write(char('b'+2*x),' ');
		--top[x];
		++pos;
		return 1;
	}
	return 0;
} 
int main(){
#ifdef cnyali_lk
	freopen("1155.in","r",stdin);
	freopen("1155.out","w",stdout);
#endif
	int n,x;
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	mn[n+1]=inf;
	for(int i=n;i;--i)mn[i]=min(mn[i+1],a[i]);
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(a[i]<a[j] && mn[j+1]<a[i]){to[i].push_back(j);to[j].push_back(i);}
	for(int i=1;i<=n;++i)col[i]=-1;
	for(int i=1;i<=n;++i)if(!~col[i])dfs(i,0);
	col[n+1]=-1;
/*	for(int i=1;i<=n;++i)write(col[i]);
	return 0;*/
	for(int i=1;i<=n;++i){
		push(col[i],a[i]);
		if(a[i]==pos){
			if(col[i]==1)while(!col[i+1] && s[0][top[0]]>a[i+1]){++i;push(0,a[i]);}
			pop(col[i]);
			while(s[0][top[0]]==pos || s[1][top[1]]==pos)pop(0)||pop(1);
		}
	}
	for(;pos<=n;){
		while(pop(0));
		while(pop(1));
	}
	
	return 0;
}

