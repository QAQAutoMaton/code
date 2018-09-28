/*
Author: CNYALI_LK
LANG: C++
PROG: c.cpp
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
template<class T>int dcmp(T a,T b){return a>b;}
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
int n,a,b,c;	
int tp[204847];
struct SMT{
	int add,mx[3],ls,rs,lc,rc;
	SMT *l,*r;
	//mx0->a+b-c
	//mx1->x+a-c
	//mx2->2x-c
	void push_up(){
		for(int i=0;i<3;++i)mx[i]=max(l->mx[i],r->mx[i]);
		lc=l->lc;
		rc=r->rc;
	}
	SMT(int la,int ra){
		ls=la;rs=ra;
		lc=rc=0;
		if(la==ra){l=r=0;mx[0]=a+b-c;mx[1]=a-c;mx[2]=-c;return;}
		int mid=(la+ra)>>1;
		l=new SMT(la,mid);
		r=new SMT(mid+1,ra);
		push_up();
	}
	void put_tag(int x){
		add+=x;for(int i=1;i<3;++i)mx[i]+=x*i;
		lc+=x;rc+=x;
	}
	void push_down(){
		l->put_tag(add);
		r->put_tag(add);
		add=0;
	}
	void Add_DPval(int pt,int w){
		if(ls==rs){
			for(int i=0;i<3;++i)mx[i]+=w;
			return;
		}
		push_down();
		if(pt<=l->rs)
			l->Add_DPval(pt,w);
		else 
			r->Add_DPval(pt,w);
		push_up();	
	}
	void Add(int la,int ra,int w){
		if(la<=ls && rs<=ra){put_tag(w);return;}
		push_down();
		if(la<=l->rs)l->Add(la,ra,w);
		if(r->ls<=ra)r->Add(la,ra,w);
		push_up();
	}
	int Qmax(int la,int ra){
		if(la<=ls && rs<=ra){
			if(tp[lc]==tp[rc])return mx[tp[lc]];
			push_down();
			return max(l->Qmax(la,ra),r->Qmax(la,ra));
		}
		push_down();
		int ans=-0x3f3f3f3f;
		if(la<=l->rs)chkmax(ans,l->Qmax(la,ra));
		if(r->ls<=ra)chkmax(ans,r->Qmax(la,ra));
		return ans;
	}
};
SMT *rt;
int cnt[204847],dp[204847],ans,unq[204847];
vector<int> rg[204847];
struct seg{
	int l,r;
};
seg sg[204847];
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	n=read();a=read();b=read();c=read();
	int l,r,mid;
	for(int i=1;i<=n;++i){
		sg[i].l=read();sg[i].r=read();
		unq[2*i-1]=sg[i].l;unq[2*i]=sg[i].r;
	}
	for(int i=0;i<a;++i)tp[i]=2;
	for(int i=a;i<b;++i)tp[i]=1;
	for(int i=b;i<=n;++i)tp[i]=0;
	sort(unq+1,unq+n+n+1);
	int m=unique(unq+1,unq+n+n+1)-unq-1;
	rt=new SMT(0,m);
	for(int i=1;i<=n;++i){
		l=lower_bound(unq+1,unq+m+1,sg[i].l)-unq;
		r=lower_bound(unq+1,unq+m+1,sg[i].r)-unq;
		++cnt[l];
		rg[r].push_back(l-1);
	}
	for(int i=1;i<=m;++i){
		rt->Add(0,i-1,cnt[i]);
//		printf("%d ",rt->Qmax(0,0));
		chkmax(ans,dp[i]=rt->Qmax(0,i-1));
//		printf("%d\n",dp[i]);
		rt->Add_DPval(i,dp[i]);
		for(auto j:rg[i])rt->Add(0,j,-1);
	}
	printf("%d\n",ans);
	return 0;
}

