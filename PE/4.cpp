/*
Author: CNYALI_LK
LANG: C++
PROG: 4.cpp
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
char s[102424];
int palind(int x){
	sprintf(s,"%d",x);
	int l=strlen(s);
	for(int i=0;i<l;++i)if(s[i]!=s[l-i-1])return 0;
	return 1;
}
int main(){
#ifdef cnyali_lk
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
#endif
	int ans=0;
	for(int i=100;i<1000;++i)for(int j=100;j<1000;++j)if(palind(i*j))chkmax(ans,i*j);
	printf("%d\n",ans);
	return 0;
}

