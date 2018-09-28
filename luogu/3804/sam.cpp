/*
Author: CNYALI_LK
LANG: C++
PROG: sam.cpp
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
	int nxt[2000005][26],lst[2000005],cnt[2000005],mx[2000005],n=1,s=1,now=1,a[2000005],b[2000005];
	void Extend(int c){
		int t=++n;
		mx[t]=mx[now]+1;
		cnt[t]=1;
		int i;
		for(i=now;i && !nxt[i][c];i=lst[i])nxt[i][c]=t;
		if(!i){lst[t]=s;}
		else if(mx[i]+1==mx[nxt[i][c]])lst[t]=nxt[i][c];
		else{
			int a,b;
			a=++n;
			b=nxt[i][c];
			mx[a]=mx[i]+1; 
			for(int j=0;j<26;++j)
				nxt[a][j]=nxt[b][j]; 
			lst[a]=lst[b];
			lst[b]=lst[t]=a;
			for(;i&&nxt[i][c]==b;i=lst[i])nxt[i][c]=a;
		}
		now=t;
	}
	void Work(){
//		for(int i=1;i<=n;++i)printf("%d,%d,%d,%d,%d\n",mx[i],cnt[i],lst[i],)
		for(int i=1;i<=n;++i)++a[mx[i]];
		for(int i=1;i<=mx[now];++i)a[i]+=a[i-1];
		for(int i=1;i<=n;++i){
			b[a[mx[i]]]=i;
			--a[mx[i]];
		}
	}
	int calc(){
		int ans=0;
		for(int i=n;i;--i){
			if(cnt[b[i]]>1)chkmax(ans,cnt[b[i]]*mx[b[i]]);
			cnt[lst[b[i]]]+=cnt[b[i]];
		}
		return ans;
	}
}
char s[1024243];
int main(){
#ifdef cnyali_lk
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
#endif
	scanf("%s",s);
	for(char *i=s;*i;++i)SAM::Extend(*i-'a');
	SAM::Work();
	printf("%d\n",SAM::calc());
	return 0;
}

