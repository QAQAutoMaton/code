/*
Author: CNYALI_LK
LANG: C++
PROG: 2698.cpp
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
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
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
bool cx[1048575];
int mn[1048575],mx[1048575];
template<const function<int(int,int)> &cmp>
struct MQ{
	int s[1048575],*l,*r;	
	MQ(){l=s+1;r=s;}
	void add(int x){
		while(l<=r && cmp(x,*r))--r;
		*(++r)=x;
	}
	void del(int x){
		if(*l==x)++l;
	}
	int top(){return *l;}
};
int increase(int a,int b){return a<b;}
int decrease(int a,int b){return a>b;}

function<int(int,int)> Inc=increase;
function<int(int,int)> Dec=decrease;
MQ<Inc> inc;
MQ<Dec> dec_;
int main(){
#ifdef cnyali_lk
	freopen("2698.in","r",stdin);
	freopen("2698.out","w",stdout);
#endif
	int n,d,x,y,l,r,xmn=0x3f3f3f3f;	
	n=read();d=read();
	for(int i=0;i<=1000000;++i)mn[i]=0x3f3f3f3f,mx[i]=-0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		x=read();y=read();
		chkmax(mx[x],y);
		chkmin(mn[x],y);
		cx[x]=1;
		chkmin(xmn,x);
	}
	l=xmn,r=xmn;	
	inc.add(mn[l]);
	dec_.add(mx[l]);
	int ans=0x3f3f3f3f;
	n=1000000;
	while(r<=n){
		while(r<=n && dec_.top()-inc.top()<d){++r;if(cx[r]){inc.add(mn[r]);dec_.add(mx[r]);}}
		while(l<r && dec_.top()-inc.top()>=d){if(cx[l]){inc.del(mn[l]);dec_.del(mx[l]);}++l;}
		if(r<=n)
		chkmin(ans,r-l+1);
	}
	if(ans==0x3f3f3f3f)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}

