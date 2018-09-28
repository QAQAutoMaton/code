/*
Author: CNYALI_LK
LANG: C++
PROG: b.cpp
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

int f[102424][4],a[102424][4],b[666666];
int N,smax[4][1111111];
void Add(int a,int x,int y){
	x+=N-1;
	chkmax(smax[a][x],y);
	for(x>>=1;x;x>>=1){
		smax[a][x]=max(smax[a][x<<1],smax[a][x<<1|1]);
	}
} 
int qmax(int a,int l,int r){
	l+=N-1;r+=N-1;
	int ans=0;
	while(l<r){
		if(l&1){chkmax(ans,smax[a][l]);++l;	}
		if(!(r&1)){chkmax(ans,smax[a][r]);--r;}
		l>>=1;r>>=1;
	}
	if(l==r)chkmax(ans,smax[a][l]);
	return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	
	int n,t=0;
	n=read();
	for(int i=0;i<3;++i)for(int j=1;j<=n;++j){a[j][i]=read();b[++t]=a[j][i];}
	sort(b+1,b+t+1);
	t=unique(b+1,b+t+1)-b-1;
	N=1;
	while(N<=t)N<<=1;
	for(int i=1;i<=n;++i)for(int j=0;j<3;++j)a[i][j]=lower_bound(b+1,b+t+1,a[i][j])-b-1;
	for(int i=1;i<=n;++i)a[i][3]=a[i][2];
	for(int i=0;i<4;++i){
		f[1][i]=1;
		Add(i,a[1][i],f[1][i]);
	}
	int ans=0;
	for(int i=2;i<=n;++i){
		for(int j=0;j<4;++j){
			chkmax(f[i][0],qmax(j,1,a[i][0])+1);
			chkmax(f[i][1],qmax(j,a[i][1],t)+1);
			if(j!=3)chkmax(f[i][2],qmax(j,a[i][2],t)+1);
			if(j!=2)chkmax(f[i][3],qmax(j,1,a[i][3])+1);
		}
		for(int j=0;j<4;++j){
			chkmax(ans,f[i][j]);
			Add(j,a[i][j],f[i][j]);
		}
	}	
	printf("%d\n",ans);
	return 0;
}

