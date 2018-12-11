/*
Author: CNYALI_LK
LANG: C++
PROG: 3239.cpp
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
typedef long long ll;
typedef pair<int,int> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
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
double notdone[2333],prob[2333];
int main(){
#ifdef cnyali_lk
	freopen("3239.in","r",stdin);
	freopen("3239.out","w",stdout);
#endif
	int T,n,r,d;	
	double p,ans; 
	scanf("%d",&T);
	for(;T;--T){
		scanf("%d%d",&n,&r);
		for(int i=1;i<=r;++i)notdone[i]=1;
		ans=0;
		for(int i=1;i<=n;++i){
			scanf("%lf%d",&p,&d);	
			prob[0]=0;
			for(int j=1;j<=r;++j){
				prob[j]=(1-prob[j-1])*notdone[j]*p;
				notdone[j]=notdone[j]*(prob[j-1]+(1-prob[j-1])*(1-p));
				printf("%.12lf|%.12lf%c",prob[j],notdone[j],j==r?'\n':' ');
				prob[j]+=prob[j-1];
			}
			ans+=prob[r]*d;
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}

