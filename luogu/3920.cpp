/*
Author: CNYALI_LK
LANG: C++
PROG: 3920.cpp
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
struct *Treap{
	Treap *l,*r;
	int v,w;
	Treap(int aw=0){
		w=aw;
		l=r=0;
		v=rand();
	}
};
Treap *merge(Treap *l,Treap *r){
	if(!l)return r;
	if(!r)return l;
	if(l->v<=r->v){
		l->r=merge(l->r,r);
		l->pushup();
		return l;
	}
	else{
		r->l=merge(l,r->l);
		r->pushup();
		return r;
	}
}
void Split(Treap *rt,Treap &(*l),Treap &(*r),int w){
	if(!rt){l=r=0;return;}
	if(rt->l<=w){
		l=rt;
		Split(rt->r,l->r,r,w);
		l->pushup();
	}
	else{
		r=rt;
		Split(rt->r,l,r->l,w);
		r->pushup();
	}
}
void remove(Treap *r){
	if(!r)return;
	remove(r->l);
	remove(r->r);
	delete r;
}
Treap *root[102424];
void insert(Treap &*root,int w){
	Treap *s=new Treap(w),*l,*r;
	Split(root,w,l,r);
	root=merge(merge(l,s),r);
}
int main(){
#ifdef cnyali_lk
	freopen("3920.in","r",stdin);
	freopen("3920.out","w",stdout);
#endif
	srand(time(0));
	read();
	int n=read();
	r[1]=read();
	for(int i=2;i<=n;++i){
		
	}
	

	return 0;
}

