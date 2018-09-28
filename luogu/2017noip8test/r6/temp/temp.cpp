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
struct seg{
	int l,r;
};
seg a[2047],b[2047];
const int p=1000000007;
int f[2047];
int cmp(seg a,seg b){return a.r<b.r||a.r==b.r && a.l<b.l;}
int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int n;
	n=read();
	for(int i=1;i<=n;++i){
		a[i].l=read();a[i].r=read();
	}
	sort(a+1,a+n+1,cmp);
	int l,r,mid,ans=0;
	for(int i=1;i<=n;++i){
		f[0]=1;
		int t=0;
		for(int j=1;j<=n;++j)if(i>j){
			if(a[i].l<=a[j].r){
				b[++t]=a[j];
				l=0,r=t-1;	
				while(l<=r){
					mid=(l+r)>>1;
					if(b[mid].r<b[t].l)l=mid+1;
					else r=mid-1;
				}
				f[t]=(f[t-1]+f[l-1])%p;
			}
		}
		else if(i<j){
			if(a[j].l<=a[i].r){
				b[++t]=a[j];
				l=0,r=t-1;	
				while(l<=r){
					mid=(l+r)>>1;
					if(b[mid].r<b[t].l)l=mid+1;
					else r=mid-1;
				}
				f[t]=(f[t-1]+f[l-1]-1)%p;
			}	
		}
		ans=(ans+f[t])%p;
	}
	printf("%d\n",ans);
	return 0;
}

