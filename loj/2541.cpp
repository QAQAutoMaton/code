/*
Author: CNYALI_LK
LANG: C++
PROG: 2541.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std; typedef long long ll;
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
typedef vector<int> vi;
vi poly[200005],*l,*r,rev;
int w[100005];
const int p=998244353,g=3,ig=332748118;
int fpm(int a,int b){int c=1;for(;b;b>>=1,a=(ll)a*a%p)if(b&1)c=(ll)c*a%p;return c;}
int sum(int a,int b){return (a+=b)>=p?a-p:a;}
void NTT(vi &a,int N,int flg){
	rev.resize(N);
	for(int i=1;i<N;++i){
		rev[i]=(rev[i>>1]>>1)|((i&1)*(N>>1));
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int i=1;i<N;i<<=1){
		int ww=fpm(flg==1?g:ig,(p-1)/i/2),w,u,v;
		for(int j=0;j<N;j+=i+i){
			w=1;
			for(int k=0;k<i;++k){
				u=a[j+k];v=(ll)a[j+k+i]*w%p;
				w=(ll)w*ww%p;
				a[j+k]=sum(u,v);
				a[j+k+i]=sum(u,p-v);
			}
		}
	}
	if(flg==-1){
		int ivn=fpm(N,p-2);
		for(int i=0;i<N;++i)a[i]=(ll)a[i]*ivn%p;
	}
}
void Multi(vi &a,vi &b,vi &c){
	int Nl=a.size()+b.size()-1,N=1;
	for(;N<Nl;N<<=1);
	a.resize(N);
	b.resize(N);
	c.resize(N);
	NTT(a,N,1);
	NTT(b,N,1);
	for(int i=0;i<N;++i)c[i]=(ll)a[i]*b[i]%p;
	NTT(c,N,-1);
	a.clear();
	b.clear();
}
int main(){
#ifdef cnyali_lk
	freopen("2541.in","r",stdin);
	freopen("2541.out","w",stdout);
#endif
	int n;
	read(n);
	if(n==1){printf("1\n");return 0;}
	for(int i=1;i<=n;++i){
		read(w[i]);
		poly[i].resize(w[i]+1);
		poly[i][0]=1;
		poly[i][w[i]]=p-1;
	}
	l=poly+2;r=poly+n;
	while(l!=r){	
		++r;
		Multi(*l,*(l+1),*r);
		l+=2;
	}
	int ans=0;
	for(int i=r->size()-1;~i;--i){
		ans=sum(ans,(ll)*(r->begin()+i)*fpm(sum(i,w[1]),p-2)%p);
	}
	ans=(ll)ans*w[1]%p;
	printf("%d\n",ans);
	return 0;
}

