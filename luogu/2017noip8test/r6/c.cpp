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
const int block=500;
const int p=1000000007;
int sum[200005],n;
int add[1887][1887];
#define lowbit(x) ((x)&-(x))
void Plus(int &x,int y){
	if((x+=y)>=p)x-=p;
}
void Add(int x,int y){
	for(;x<=n;x+=lowbit(x))Plus(sum[x],y);
}
int Sum(int x){
	int ans=0;
	for(int i=x;i;i^=lowbit(i))Plus(ans,sum[i]);
	for(int i=1;i<=block;++i)Plus(ans,((ll)x/i*add[i][i]+add[i][x%i])%p);
	return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	n=read();
	int m=read(),l,r,x,y,z;
	for(int i=1;i<=n;++i)Add(i,read());
	for(int i=1;i<=m;++i){
		if(read()==1){
			x=read();y=read();z=read();
			if(x<=block){
				for(int j=y;j<=x;++j)Plus(add[x][j],z);
			}
			else{
				for(;y<=n;y+=x)Add(y,z);
			}
		}	
		else{
			l=read()-1;
			r=read();
			int ans=Sum(r);
			Plus(ans,p-Sum(l));
			printf("%d\n",ans);
		}
	}
	return 0;
}

