/*
Author: CNYALI_LK
LANG: C++
PROG: 1903.cpp
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
const int blk=37,klk=37*37;
int ta[102424],tb[102424],tc[102424];
int ans[102424];
struct ask{
	int l,r,w,is;
	void init(int id,int x){
		l=read();r=read();w=x;
		is=id;
	}
};
ask a[102424];
int Qcmp(ask a,ask b){
	if(a.l/klk==b.l/klk){
		if(a.r/blk==b.r/blk)return a.w<b.w;	
		else return a.r<b.r;
	}else return a.l<b.l;
}
int w[102424];
int c[1024242],l,r,cnt;
void change(int a,int col){
	if(l<=a&&a<=r){
		if(!(--c[w[a]]))--cnt;
		if(!c[col])++cnt;
		++c[col];
	}
	w[a]=col;
}
void add(int x){
	if(!c[w[x]])++cnt;
	++c[w[x]];
}
void rem(int x){
	if(!(--c[w[x]]))--cnt;
}
char readch(){
	char c;
	while(!isalpha(c=getchar()));
	return c;
}
int main(){
#ifdef cnyali_lk
	freopen("1903.in","r",stdin);
	freopen("1903.out","w",stdout);
#endif
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;++i)w[i]=read();
	int q=0,p=0;
	while(m){
		--m;
		if(readch()^'R'){
			a[++q].init(q,p);
		}
		else{
			int u,v;
			u=read();v=read();
			ta[++p]=u;
			tb[p]=v;
			tc[p]=w[u];
			w[u]=v;
		}
	}
	sort(a+1,a+q+1,Qcmp);
	l=1;r=n;
	for(int i=1;i<=n;++i){
		add(i);
	}
	int t=p;
	for(int i=1;i<=q;++i){
		while(t<a[i].w){
			++t;
			change(ta[t],tb[t]);
		}
		while(t>a[i].w){
			change(ta[t],tc[t]);
			--t;
		}
		while(l>a[i].l)add(--l);
		while(r<a[i].r)add(++r);
		while(l<a[i].l)rem(l),++l;
		while(r>a[i].r)rem(r),--r;
		ans[a[i].is]=cnt;
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}
