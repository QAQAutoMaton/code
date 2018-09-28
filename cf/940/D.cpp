/*
Author: CNYALI_LK
LANG: C++
PROG: D.cpp
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
int a[102424],b[102424];
int main(){
#ifdef cnyali_lk
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n;
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		char c;
		while(!isdigit(c=getchar()));
		b[i]=c-'0';
	}
	int rmax=1000000000,rmin=-1000000000;
	int lmax=1000000000,lmin=-1000000000;
	int t;
	for(int i=5;i<=n;++i){
		if(b[i-1]==b[i-2] && b[i-2]==b[i-3]&&b[i-3]==b[i-4]){
			if(b[i]==b[i-1]){
				if(b[i]){
					t=min(a[i],min(a[i-1],min(a[i-2],min(a[i-3],a[i-4]))));
					chkmax(rmin,t);
				}
				else{
					t=max(a[i],max(a[i-1],max(a[i-2],max(a[i-3],a[i-4]))));
					chkmin(lmax,t);
				}
			}
			else{
				if(!b[i]){
					t=min(a[i],min(a[i-1],min(a[i-2],min(a[i-3],a[i-4]))))-1;
					chkmin(rmax,t);
				}
				else{
					t=max(a[i],max(a[i-1],max(a[i-2],max(a[i-3],a[i-4]))))+1;
					chkmax(lmin,t);
				}
			}
		}
	}
	printf("%d %d\n",lmin,rmax);
	return 0;
}

