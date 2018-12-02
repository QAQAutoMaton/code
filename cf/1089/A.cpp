/*
Author: CNYALI_LK
LANG: C++
PROG: A.cpp
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
void work(int a,int b){
	int fa=a,fb=b;
	for(int bw=0;bw<=2;++bw){
		a-=50;b-=25*bw;
		if(a<0 || b<0){a=fa;b=fb;break;}
		int mx=bw==2?15:25;
		if(a>=mx && a-mx<=23*bw && b<=46+mx-2){
			a-=mx;
			printf("3:%d\n",bw);
			for(int i=1;i<=bw;++i)if(a>=23){
				printf("23:25 ");
				a-=23;
			}
			else printf("%d:25 ",a),a=0;
			for(int i=1;i<=2;++i)if(b>=23){
				printf("25:23 ");
				b-=23;
			}
			else printf("25:%d ",b),b=0;
			printf("%d:%d\n",mx,b);
			return;

		}
		for(int i=mx;i<=a;++i){
			if(b>=i-2){
				a-=i;
				b-=i-2;
				if(a<=23*bw && b<=46){
					printf("3:%d\n",bw);
					for(int i=1;i<=bw;++i)if(a>=23){
						printf("23:25 ");
						a-=23;
					}
					else printf("%d:25 ",a),a=0;
					for(int i=1;i<=2;++i)if(b>=23){
						printf("25:23 ");
						b-=23;
					}
					else printf("25:%d ",b),b=0;
					printf("%d:%d\n",i,i-2);
					return;
				}
				a+=i;
				b+=i-2;
			}
		}
		if(mx==15){
			for(int i=25;i<=a;++i){
				if(b>=i-2){
					a-=i;
					b-=i-2;
					if(a<=46 && b<=36){
						printf("3:%d\n",bw);
						for(int i=1;i<=bw;++i)if(a>=23){
							printf("23:25 ");
							a-=23;
						}
						else printf("%d:25 ",a),a=0;

						printf("%d:%d\n",i,i-2);
						if(b>=23){
							printf("25:23 ");
							b-=23;
						}
						else printf("25:%d ",b),b=0;

						if(b>=13){
							printf("15:13 ");
							b-=13;
						}
						else printf("15:%d ",b),b=0;
						return;
					}
					a+=i;
					b+=i-2;
				}
			}
		}
		a=fa;b=fb;
	}

	for(int aw=0;aw<=2;++aw){
		b-=50;a-=25*aw;

		if(a<0 || b<0){a=fa;b=fb;break;}
		int mx=aw==2?15:25;
		if(b>=mx && b-mx<=23*aw && a<=46+mx-2){
			b-=mx;
			printf("%d:3\n",aw);
			for(int i=1;i<=aw;++i)if(b>=23){
				printf("25:23 ");
				b-=23;
			}
			else printf("25:%d ",b),b=0;
			for(int i=1;i<=2;++i)if(a>=23){
				printf("23:25 ");
				a-=23;
			}
			else printf("%d:25 ",a),a=0;
			printf("%d:%d\n",a,mx);
			return;

		}

		for(int i=mx;i<=b;++i){
			if(a>=i-2){
				b-=i;
				a-=i-2;
				if(b<=46 && a<=36){
					printf("%d:3\n",aw);
					for(int i=1;i<=aw;++i)if(b>=23){
						printf("25:23 ");
						b-=23;
					}
					else printf("25:%d ",b),b=0;

					printf("%d:%d\n",i-2,i);
					if(a>=23){
						printf("23:25 ");
						a-=23;
					}
					else printf("%d:25 ",a),a=0;

					if(a>=13){
						printf("13:15 ");
						a-=13;
					}
					else printf("%d:15 ",a),a=0;
					return;
				}
				a+=i-2;
				b+=i;
			}
		}
		if(mx==15){
			for(int i=25;i<=b;++i){

			if(a>=i-2){
				b-=i;
				a-=i-2;
				if(b<=46 && a<=36){
					printf("%d:3\n",aw);
					for(int i=1;i<=aw;++i)if(b>=23){
						printf("25:23 ");
						b-=23;
					}
					else printf("25:%d ",b),b=0;

					printf("%d:%d\n",i-2,i);
					if(a>=23){
						printf("23:25 ");
						a-=23;
					}
					else printf("%d:25 ",a),a=0;

					if(a>=13){
						printf("13:15 ");
						a-=13;
					}
					else printf("%d:15 ",a),a=0;
					return;
				}
				a+=i-2;
				b+=i;
			}
				if(a>=i-2){
					b-=i;
					a-=i-2;
					if(b<=23*aw && a<=46){
						printf("%d:3\n",aw);
						for(int i=1;i<=aw;++i)if(b>=23){
							printf("25:23 ");
							b-=23;
						}
						else printf("25:%d ",b),b=0;
						for(int i=1;i<=2;++i)if(a>=23){
							printf("23:25 ");
							a-=23;
						}
						else printf("%d:25 ",a),a=0;
						printf("%d:%d\n",i-2,i);
						return;
					}
					a+=i-2;
					b+=i;
				}
			}
		}
		a=fa;b=fb;
	}
	printf("Impossible\n");
}
int main(){
#ifdef cnyali_lk
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int n,a,b;
	read(n);
	for(;n;--n){
		read(a,b);
		work(a,b);
	}
	return 0;
}

