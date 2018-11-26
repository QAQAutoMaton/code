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
const int N = 1000010;
int a[N], maxv[N << 2], addv[N << 2];
#define lson (o << 1)
#define rson (o << 1 | 1)
void pushup(int o) {
    maxv[o] = max(maxv[lson], maxv[rson]);
}
void pushdown(int o) {
    if(!addv[o])return;
    addv[lson] += addv[o];
    addv[rson] += addv[o];
    maxv[lson] += addv[o];
    maxv[rson] += addv[o];
    addv[o] = 0;
}
void build(int o, int l, int r) {
    if(l == r) {
        maxv[o] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(o);
}
pii operator +(pii a,pii b){
	return make_pair(max(a.x,b.x),a.y+b.y*(1+(a.x<b.x)));
}
void update(int o,int l,int r,int ql,int qr,int w){
	if(ql<=l && r<=qr){addv[o]+=w;maxv[o]+=w;return;}	
    int mid = (l + r) >> 1;
    pushdown(o);
    if(ql <= mid) update(lson, l, mid, ql, qr,w);
    if(qr > mid) update(rson, mid + 1, r, ql, qr,w);
	pushup(o);
} 
pii query(int o, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return make_pair(maxv[o],1);
    int mid = (l + r) >> 1;
    pushdown(o);
    pii ans = make_pair(-inf,1);
    if(ql <= mid) ans = ans+query(lson, l, mid, ql, qr);
    if(qr > mid) ans = ans+query(rson, mid + 1, r, ql, qr);
    return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,q,tp,l,r,w;
	read(n,q);
	for(int i=1;i<=n;++i)read(a[i]);
	build(1,1,n);
	for(;q;--q){
		read(tp,l,r);
		if(tp==1){read(w);update(1,1,n,l,r,w);}
		else printf("%d\n",query(1,1,n,l,r).y);
	}
	return 0;
}

