/*
Author: CNYALI_LK
LANG: C++
PROG: 3721.cpp
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
int type[102424],lsh[102424],w[102424],t,ds;
struct smt{
	smt *l,*r;
	int cnt,add,_l,_r;
	smt(int l_,int r_){
		_l=l_;_r=r_;
		if(l_!=r_){
			int mid=(_l+_r)>>1;	
			l=new smt(l_,mid);
			r=new smt(mid+1,r_);
		}
		cnt=0;
	}
	void upd(int x,int s){
		cnt+=s;
		if(_l<_r)if(x<r->_l)l->upd(x,s);
		else r->upd(x,s);
	}
	void _add(int l_,int r_,int w){
		if(l_<=_l&&_r<=r_){
			add+=w;
			return;
		} if(l_<=l->_r)l->_add(l_,r_,w);
		if(r_>=r->_l)r->_add(l_,r_,w);
	}
	int prev(int x){
		if((!cnt)||x<_l)return 0;
		if(_l==_r)return _l;
		int s=r->prev(x);
		return s?s:l->prev(x);	
	}
	int next(int x){
		if((!cnt)||_r<x)return 0;
		if(_l==_r)return _l;
		int s=l->next(x);
		return s?s:r->next(x);
	}
	int height(int x){
		if(!x)return 0;
		if(_l==_r)return add;
		if(x<=l->_r)return add+l->height(x);
		else return add+r->height(x);
	}
};
smt *root;
int fa[102424],son[102424][2],ps,_root;
void insert(int x){
	fa[x]=son[x][0]=son[x][1]=0;
	if(!ps){
		root->_add(x,x,1-root->height(x));
		_root=x;
		++ps;
		write(1,'\n');
	}
	else{
		++ps;
		int sl=root->prev(x),sr=root->next(x);
		int hl=root->height(sl),hr=root->height(sr);
		if(hl<hr){
			fa[x]=sr;
			son[sr][0]=x;
			root->_add(x,x,hr+1-root->height(x));

			printf("%d\n",hr+1);
		}
		else{
			fa[x]=sl;
			son[sl][1]=x;
			root->_add(x,x,hl+1-root->height(x));
			printf("%d\n",hl+1);
		}
	}
	root->upd(x,1);
}
void splay_min(){
	int x=root->next(1);
	if(_root==x){printf("1\n");return;}
	else{
		int w;
		printf("%d\n",w=root->height(x));
		root->_add(x,x,1-w);
		son[fa[x]][0]=son[x][1];
		fa[son[x][1]]=fa[x];
		root->_add(fa[x],t,1);
		son[fa[_root]=x][1]=_root;
		_root=x;
	}
}
void splay_max(){
	int x=root->prev(t);
	if(_root==x)printf("1\n");
	else{
		int w=root->height(x);
		printf("%d\n",w);
		root->_add(x,x,1-w);
		son[fa[x]][1]=son[x][0];
		fa[son[x][0]]=fa[x];
		root->_add(1,fa[x],1);
		son[fa[_root]=x][0]=_root;
		_root=x;
	}
}
void remove_min(){
	int x=root->next(1);
	if(x==_root){
		fa[_root=son[x][1]]=0;
		root->_add(1,t,-1);
		printf("1\n");
	}
	else{
		printf("%d\n",root->height(x));
		root->_add(x+1,fa[x]-1,-1);	
		fa[son[x][1]]=fa[x];
		son[fa[x]][0]=son[x][1];
	}

	root->upd(x,-1);
}

void remove_max(){
	int x=root->prev(t);
	if(x==_root){
		fa[_root=son[x][0]]=0;
		root->_add(1,t,-1);
		printf("1\n");
	}
	else{
		printf("%d\n",root->height(x));
		root->_add(fa[x]+1,x-1,-1);	
		fa[son[x][0]]=fa[x];
		son[fa[x]][1]=son[x][0];
	}

	root->upd(x,-1);
}
int main(){
#ifdef cnyali_lk
	freopen("3721.in","r",stdin);
	freopen("3721.out","w",stdout);
#endif
	int n;
	n=read();
	for(int i=n;i;--i){
		type[i]=read();
		if(type[i]==1){
			lsh[++t]=w[i]=read();
		}
	}
	sort(lsh+1,lsh+t+1);
	for(int i=1;i<=n;++i){
		if(type[i]==1){w[i]=lower_bound(lsh+1,lsh+t+1,w[i])-lsh;}
	}
	root=new smt(1,t);

	while(n){
		if(type[n]==1){
			insert(w[n]);
		}
		else if(type[n]==2){
			splay_min();
		}
		else if(type[n]==3){
			splay_max();
		}
		else if(type[n]==4){
			remove_min();
		}
		else{
			remove_max();
		}
		--n;
	}
	return 0;
}

