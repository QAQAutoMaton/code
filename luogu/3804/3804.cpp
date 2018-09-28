// luogu-judger-enable-o2
/*
Author: CNYALI_LK
LANG: C++
PROG: 3804.cpp
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
namespace SAM{
	struct Node{
		Node *nxt[26],*lst;
		int mx,cnt;
		Node(int Mx=0){mx=Mx;cnt=1;}
	};
	Node *s,*now,*a[2000005];
	int n;
	void init(){
		now=s=a[1]=new Node();
		n=1;
	}
	Node *extend(int c){
		Node *t=a[++n]=new Node(now->mx+1),*i;
		for(i=now;i && !i->nxt[c];i=i->lst)i->nxt[c]=t;
		if(!i){
			t->lst=s;
		}
		else if(i->mx+1==i->nxt[c]->mx){
			t->lst=i->nxt[c];
		}
		else{
			Node *nw=a[++n]=new Node(),*ths=i->nxt[c];	
			*nw=*ths;
			nw->cnt=0;
			nw->mx=i->mx+1;
			ths->lst=t->lst=nw;
			for(;i&& i->nxt[c]==ths;i=i->lst)i->nxt[c]=nw;
		}
		now=t;
		return t;
	}
	int cnt[2000005],b[2000005];
	int Work(){
//		for(int i=1;i<=now->mx;++i)cnt[i]=0;
		for(int i=1;i<=n;++i){++cnt[a[i]->mx];}	
		for(int i=1;i<=now->mx;++i)cnt[i]+=cnt[i-1];
		for(int i=1;i<=n;++i){
			b[cnt[a[i]->mx]]=i;
			--cnt[a[i]->mx];
		}
		int ans=0;
		for(int i=n;i>1;--i){
			if(a[b[i]]->cnt>1)chkmax(ans,a[b[i]]->cnt*a[b[i]]->mx);
			a[b[i]]->lst->cnt+=a[b[i]]->cnt;
		}
		return ans;
	}
};
char s[1024232];
int main(){
#ifdef cnyali_lk
	freopen("3804.in","r",stdin);
	freopen("3804.out","w",stdout);
#endif
	fread(s,1000005,1,stdin);
	SAM::init();
	for(int i=0;s[i];++i){
		SAM::extend(s[i]-'a');
	}
	printf("%d\n",SAM::Work());
	return 0;
}

