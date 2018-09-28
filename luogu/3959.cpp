/*
Author: CNYALI_LK
LANG: C++
PROG: 3959.cpp
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
int f[15][4096];
int dis[531441],fa_Q[4096];
int a[12][12];
int stk[4096],t0p;
int lowbit(int x){return x&-x;}
int g(int a,int b){
	return fa_Q[a]+fa_Q[b]*2;
}


int main(){
#ifdef cnyali_lk
	freopen("3959.in","r",stdin);
	freopen("3959.out","w",stdout);
#endif
	int n,u,v,m;
	n=read();
	if(n==1){printf("0\n");return 0;}
	m=read();
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<n;++i){
		f[1][1<<i]=0;
	}	
	memset(dis,0x3f,sizeof(dis));

	int t=1<<n;
	for(int i=1;i<t;++i)fa_Q[i]=fa_Q[i>>1]*3+(i&1);
	while(m){
		u=1<<(read()-1);v=1<<(read()-1);
		chkmin(dis[g(u,v)],read());
		dis[g(v,u)]=dis[g(u,v)];
		--m;
	}	
	
	int _t=t-1;
	for(int i=1;i<t;++i){
		for(int j=i^_t;j;j=(j-1)&(i^_t))stk[++t0p]=j;
		while(t0p){
			if(stk[t0p]==lowbit(stk[t0p]))chkmin(dis[g(i,stk[t0p])],min(dis[g(i^lowbit(i),stk[t0p])],dis[g(lowbit(i),stk[t0p])]));
			else chkmin(dis[g(i,stk[t0p])],dis[g(i,stk[t0p]^lowbit(stk[t0p]))]+dis[g(i,lowbit(stk[t0p]))]);
			--t0p;
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<n;++i){
		for(int j=1;j<t;++j)for(int k=_t^j;k;k=(k-1)&(_t^j))if(dis[g(j,k)]!=0x3f3f3f3f)chkmin(f[i+1][j|k],f[i][j]+dis[g(j,k)]*i);
		chkmin(ans,f[i][_t]);
	}
	printf("%d\n",ans);
	return 0;
}

