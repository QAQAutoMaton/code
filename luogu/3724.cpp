/*
Author: CNYALI_LK
LANG: C++
PROG: 3724.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#include<ext/hash_set>
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
typedef pair<pii,int> piii;
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
int f[128][128],a[128],w[128];
int t,tot;
pii ok[4000005];
struct hashset{
	int w=101,p=1000007;
	int beg[1000007],lst[4000005],e;
	ll val[4000005];
	void insert(ll x){
		int a=x%p;
		val[++e]=x;
		lst[e]=beg[a];
		beg[a]=e;
	}
	int count(ll x){
		int a=x%p;
		for(int i=beg[a];i;i=lst[i])if(val[i]==x)return 1;
		return 0;
	}
}st;
queue<piii>q;
void bfs(){
	st.insert(101);
	q.push(make_pair(make_pair(1,0),1));
	ok[t=1]=make_pair(1,1);
	int s=0,w=0;
	while(!q.empty()){
		piii s=q.front();q.pop();
		if(s.y==tot)break;
		++s.y;
		++s.x.y; q.push(s);
		--s.x.y;
		if(s.x.y>1 && (ll)s.x.x*s.x.y<=1e8 && !st.count(s.x.x*s.x.y*101LL+s.x.y)){
			s.x.x*=s.x.y;
			st.insert(s.x.x*101LL+s.x.y);
			ok[++t]=make_pair(s.x.x,s.y);
			q.push(s);
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("3724.in","r",stdin);
	freopen("3724.out","w",stdout);
#endif
	int n,m,mc;
	n=read();m=read();mc=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)w[i]=read();
	for(int i=0;i<=n;++i)for(int j=0;j<=mc;++j)f[i][j]=-0x3f3f3f3f;
	f[0][mc]=0;
	for(int i=1;i<=n;++i)for(int j=a[i];j<=mc;++j){
		chkmax(f[i][j-a[i]],f[i-1][j]+1);
		chkmax(f[i][min(j-a[i]+w[i],mc)],f[i-1][j]);
	}
	for(int i=1;i<=n;++i)for(int j=0;j<=mc;++j)chkmax(tot,f[i][j]);
	bfs();
	sort(ok+1,ok+t+1);
	for(int i=2;i<=t;++i){
		chkmin(ok[i].y,ok[i-1].y+ok[i].x-ok[i-1].x);
	}
	for(;m;--m){
		int orz=read(),fafa=0;
		for(int i=0,j=t;i<=t&&!fafa;++i){
			while(j&&ok[i].x+ok[j].x>orz)--j;	
			if(j && ok[i].x+ok[j].x+tot-ok[i].y-ok[j].y>=orz){fafa=1;}
		}
		write(fafa,'\n');
	}
	return 0;
}

