/*
Author: CNYALI_LK
LANG: C++
PROG: d.cpp
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
int a[102424],n;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int solve(){
	int xs=1,zs;
	while(1){
		zs=0;
		for(int i=1;i<=n;++i)if(a[i]==1)zs=1;
		if(zs){
			for(int i=1;i<=n;++i)xs=xs^((a[i]-1)&1);
			return !xs;
		}
		for(int i=1;i<=n;++i)if(!(a[i]&1))++zs;
		if(zs&1)return xs;
		else if(n-zs>1)return !xs;
		int g=0;
		for(int i=1;i<=n;++i){
			if(a[i]&1)--a[i];
			g=gcd(g,a[i]);
		}
		for(int i=1;i<=n;++i)a[i]/=g;
		xs^=1;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	printf(solve()?"First\n":"Second\n");
	return 0;
}

