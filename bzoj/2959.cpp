/*
Author: CNYALI_LK
LANG: C++
PROG: 2959.cpp
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
namespace dsu{
	int fa[150005];
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void join(int a,int b){
		fa[find(a)]=find(b);
	}
}
namespace LCT{
	int fa[150005],son[150005][2],ws[150005],bel[150005],rev[150005],sum[150005];
	int belong(int x){return x==bel[x]?x:bel[x]=belong(bel[x]);}
#define fa(x) (fa[x]=belong(fa[x]))
#define lc(x) son[x][0]
#define rc(x) son[x][1]
#define ntr(x) (fa(x)&&(lc(fa(x))==x||rc(fa(x))==x))
#define ffx(x) (rc(fa(x))==x)
#define push_up(x) sum[x]=sum[lc(x)]+sum[rc(x)]+ws[x]
	void push_tag(int x){ if(ntr(x))push_tag(fa(x));
		if(rev[x]){
			rev[lc(x)]^=1;
			rev[rc(x)]^=1;
			swap(lc(x),rc(x));
			rev[x]=0;
		}
	}
	void rotate(int x){
		int f=fa(x),ff=fa(f),slr=ffx(x);
		fa[f]=x;
		fa[x]=ff;
		if(rc(ff)==f)rc(ff)=x;
		if(lc(ff)==f)lc(ff)=x;
		fa[son[f][slr]=son[x][slr^1]]=f;
		son[x][slr^1]=f;
		
		push_up(f);
		push_up(x);
	}
	void splay(int x){
		push_tag(x);
		while(ntr(x)){
			int f=fa(x);
			if(ntr(f)){
				if(ffx(x)==ffx(f))rotate(f);
				else rotate(x);
			}
			rotate(x);
		}
	}
	void access(int x){
		int y=0;
		while(x){
			splay(x);
			rc(x)=y;
			push_up(x);
			y=x;x=fa(x);
		}
	}
	void as(int x){access(x);splay(x);}
	void mtr(int x){as(x);rev[x]^=1;}
	void link(int x,int y){
		mtr(x);as(y);
		fa[x]=y;
	}
	int query(int x,int y){
		mtr(x);
		as(y);
		return sum[y];
	}
	void merge(int x,int y){
		if(!x)return;
		ws[y]+=ws[x];
		bel[x]=y;
		merge(lc(x),y);
		merge(rc(x),y);
	}
}
int w[150005];
void merge(int u,int v){
	if(dsu::find(u)!=dsu::find(v)){
		LCT::link(u,v);	
		dsu::join(u,v);
	}
	else{
		if(LCT::belong(u)!=LCT::belong(v)){
			LCT::mtr(u);
			LCT::as(v);
			LCT::merge(LCT::son[v][0],v);
		}	
	}
}
int main(){
#ifdef cnyali_lk
	freopen("2959.in","r",stdin);
	freopen("2959.out","w",stdout);
#endif
	int n,m,opt,x,y;
	n=read();m=read();
	for(int i=1;i<=n;++i)dsu::fa[i]=LCT::bel[i]=i;
	for(int i=1;i<=n;++i)w[i]=LCT::ws[i]=LCT::sum[i]=read();
	for(;m;--m){
		opt=read();x=read();y=read();	
		if(opt==1){
			merge(LCT::belong(x),LCT::belong(y));
		}
		else if(opt==2){
			LCT::ws[LCT::belong(x)]+=y-w[x];
			LCT::splay(LCT::belong(x));
			w[x]=y;
		}
		else{
			if(dsu::find(x)!=dsu::find(y))printf("%d\n",-1);
			else printf("%d\n",LCT::query(LCT::belong(x),LCT::belong(y)));
		}
	}
	return 0;
}

