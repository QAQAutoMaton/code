/*
Author: CNYALI_LK
LANG: C++
PROG: e.cpp
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
int read_z(){
	int s=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='*')return 0x3f3f3f3f;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s;
}
int a[505][505];
const int gx[4]={0,1,0,-1};
const int gy[4]={1,0,-1,0};
namespace algo1{
	int dis[505][505],out[255555];
	priority_queue<pii,vector<pii>,greater<pii> >p;
	int dij(int n,int m,int x,int y,int tx,int ty){
		while(!p.empty())p.pop();
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){dis[i][j]=0x3f3f3f3f;out[i*m+j-1]=0;}
		dis[x][y]=a[x][y];
		p.push(make_pair(a[x][y],x*m+y-1));
		while(!p.empty()){
			pii s=p.top();
			p.pop();
			if(out[s.y])continue;
			out[s.y]=1;
			x=s.y/m;
			y=s.y%m+1;
			for(int i=0;i<4;++i){
				if(chkmin(dis[x+gx[i]][y+gy[i]],dis[x][y]+a[x+gx[i]][y+gy[i]])){
					p.push(make_pair(dis[x+gx[i]][y+gy[i]],(x+gx[i])*m+(y+gy[i]-1)));	
				}
			}
		}	
		return dis[tx][ty]==0x3f3f3f3f?-1:dis[tx][ty];
	}
}
namespace algo2{
	int dis[505][505][4],out[2555555];
	priority_queue<pii,vector<pii>,greater<pii> >p;
	int dij(int n,int m,int x,int y,int tx,int ty){
		while(!p.empty())p.pop();
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)for(int k=0;k<4;++k){dis[i][j][k]=0x3f3f3f3f;out[(i*m+j-1)*4+k]=0;}
		dis[x][y][0]=dis[x][y][1]=dis[x][y][2]=dis[x][y][3]=a[x][y];
		for(int i=0;i<4;++i)p.push(make_pair(a[x][y],(x*m+y-1)*4+i));
		int w;
		while(!p.empty()){
			pii s=p.top();
			p.pop();
			if(out[s.y])continue;
			out[s.y]=1;
			x=s.y/4/m;
			y=s.y/4%m+1;
			w=s.y%4;
			for(int i=0;i<4;++i)if(i!=w){
				if(chkmin(dis[x+gx[i]][y+gy[i]][i],dis[x][y][w]+a[gx[i]+x][gy[i]+y])){
					p.push(make_pair(dis[x+gx[i]][y+gy[i]][i],((x+gx[i])*m+(y+gy[i]-1))*4+i));	
				}
			}
		}	
		int ans=0x3f3f3f3f;
		for(int i=0;i<4;++i)chkmin(ans,dis[tx][ty][i]);
		return ans==0x3f3f3f3f?-1:ans;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	int n,m,r1,c1,r2,c2,no=0;
	while(~scanf("%d%d%d%d%d%d",&n,&m,&r1,&c1,&r2,&c2)){
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
			a[i][j]=read_z();
//			printf("%d%c",a[i][j],j==m?'\n':' ');
		}
		printf("Case %d: %d %d\n",++no,algo1::dij(n,m,r1,c1,r2,c2),algo2::dij(n,m,r1,c1,r2,c2));
	}
	return 0;
}

