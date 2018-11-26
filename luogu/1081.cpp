/*
Author: CNYALI_LK
LANG: C++
PROG: 1081.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
ll a[100005];
bool operator <(pii u,pii v){return u.x<v.x||u.x==v.x && a[u.y]<a[v.y];}
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a>b?b:a;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline void read (ll &x) {
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
	// prll a signed lleger
	inline void write (ll x) {
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
const ll inf=0x7fffffff;
ll ls[3000005],rs[3000005],cnt[3000005],t; 
ll anx[21][100005],bnx[100005],as[21][100005],bs[100005],n,alls[21][100005];
void insert(ll x,ll y){
	ll r=1;
	for(ll i=30;~i;--i){
		++cnt[r];
		if(x<(1<<i)){
			if(!ls[r])ls[r]=++t;
			r=ls[r];
		}
		else{
			if(!rs[r]){rs[r]=++t;}
			r=rs[r];
			x-=1<<i;	
		}
	}
	cnt[r]=y;
}
pii o(inf,inf);
pii pre(ll x,ll rt=1,ll t=31,ll w=0){
	if(x<w)return o;
	if(!rt)return o;
	if(!t)return make_pair(x-w,cnt[rt]);
	pii s;
	if(o!=(s=pre(x,rs[rt],t-1,w+(1LL<<(t-1)))))return s;
	return pre(x,ls[rt],t-1,w);
}
pii nxt(ll x,ll rt=1,ll t=31,ll w=0){
	if(w+(1LL<<t)<=x)return o;
	if(!rt)return o;
	if(!t)return make_pair(w-x,cnt[rt]);
	pii s;
	if(o!=(s=nxt(x,ls[rt],t-1,w)))return s;
	return nxt(x,rs[rt],t-1,w+(1LL<<(t-1)));
}
pii calc(ll s,ll x){
	pii ans(0,0);

	for(ll i=18;~i;--i){
		if(x>=alls[i][s]){
			x-=alls[i][s];
			ans.x+=as[i][s];
			ans.y+=alls[i][s]-as[i][s];
			s=anx[i][s];
		}
	}
	return ans;
}
void calc1(){
	ll x,wx=0x3f3f3f3f,wy=1,s=1;
	pii a;
	read(x);
	for(ll i=1;i<=n;++i){a=calc(i,x);if(a.x*wy<wx*a.y){wx=a.x;wy=a.y;s=i;}}
	write(s,'\n');
}
void calc2(){
	ll m,s,x;
	pii a;
	read(m);
	for(;m;--m){
		read(s,x);
		a=calc(s,x);
		write(a.x,' ',a.y,'\n');
	}
}
int main(){
#ifdef cnyali_lk
	freopen("1081.in","r",stdin);
	freopen("1081.out","w",stdout);
#endif
	t=1;
	pii Pre,Nxt;
	read(n);
	for(ll i=1;i<=n;++i){
		read(a[i]);
		a[i]+=1<<30;
	}
	ll s;
	for(ll i=n;i;--i){
		if(i==n){anx[0][i]=bnx[i]=i;as[0][i]=bs[i]=inf;}
		else{
			Pre=pre(a[i]);
			Nxt=nxt(a[i]);
			if(i==n-1){anx[0][i]=i;bnx[i]=min(Pre,Nxt).y;as[0][i]=inf;bs[i]=min(Pre,Nxt).x;}
			else{
				if(Nxt<Pre){
					bnx[i]=Nxt.y;
					bs[i]=Nxt.x;
					s=(a[Nxt.y]+1-a[i]);
					Nxt=nxt(a[Nxt.y]+1);
					Nxt.x+=s;
				}
				else{
					bnx[i]=Pre.y;
					bs[i]=Pre.x;
					s=(a[i]-a[Pre.y]+1);
					Pre=pre(a[Pre.y]-1);
					Pre.x+=s;
				}
				if(Nxt<Pre)Pre=Nxt;
				anx[0][i]=Pre.y;
				as[0][i]=Pre.x;
			}
		}
		alls[0][i]=as[0][i];
//		write(anx[0][i],' ',as[0][i],' ',alls[0][i],' ',bnx[i],' ',bs[i],'\n');
		insert(a[i],i);
	}
	for(ll i=1;i<=n;++i){
		anx[1][i]=bnx[anx[0][i]];
		as[1][i]=as[0][i];
		alls[1][i]=as[0][i]+bs[anx[0][i]];
	}
	for(ll i=2;i<=18;++i){
		for(ll j=1;j<=n;++j){
			alls[i][j]=alls[i-1][j]+alls[i-1][anx[i-1][j]];
			as[i][j]=as[i-1][j]+as[i-1][anx[i-1][j]];
			anx[i][j]=anx[i-1][anx[i-1][j]];
		}
	}
	calc1();
	calc2();
	return 0;
}

