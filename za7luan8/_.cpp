/*
Author: CNYALI_LK
LANG: C++
PROG: _.cpp
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
char s[2047];
char *a[2047];
int cmp(char *a,char *b){return strcmp(a,b)<0;}
int main(){
#ifdef cnyali_lk
	freopen("_.in","r",stdin);
	freopen("_.out","w",stdout);
#endif
	scanf("%s",s+1);	
	int n=strlen(s+1),k;
	scanf("%d",&k);
	for(int i=1;i<=n;++i)a[i]=s+i;
	sort(a+1,a+n+1,cmp);
	printf("%s\n",a[k]);
	return 0;
}

