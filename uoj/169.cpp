/*
Author: CNYALI_LK
LANG: C++
PROG: 169.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int read(){
	int s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
int a[500100];
struct smt{
	smt *l,*r;
	int ls,rs;
	int mn,sm,add,minadd,mc;
	void push_up(){
		mn=min(l->mn,r->mn);
		mc=0;
		if(l->mn==mn)mc+=l->mc;
		if(r->mn==mn)mc+=r->mc;
		sm=0x3f3f3f3f;
		if(l->mn!=mn)chkmin(sm,l->mn);
		else chkmin(sm,l->sm);
		
		if(r->mn!=mn)chkmin(sm,r->mn);
		else chkmin(sm,r->sm);
	}
	smt(int lx,int rx){
		ls=lx;rs=rx;
		if(lx==rx){
			mn=a[lx];
			sm=0x3f3f3f3f;
			mc=1;
		}
		else{
			int mid=(lx+rx)>>1;
			l=smt(lx,mid);
			r=smt(mid+1,rx);
			push_up();
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("169.in","r",stdin);
	freopen("169.out","w",stdout);
#endif
	int n,m;
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	
	return 0;
}

