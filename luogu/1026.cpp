/*
Author: CNYALI_LK
LANG: C++
PROG: 1026.cpp
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
char st[1023],t[1023]; int wa[1023],w[1023][1023]; int f[43][1023];
int main(){
#ifdef cnyali_lk
	freopen("1026.in","r",stdin);
	freopen("1026.out","w",stdout);
#endif
	int p,k,s;
	scanf("%d%d\n",&p,&k);
	for(int i=0;i<p;++i){
		scanf("%s",t);
		
		strcat(st,t);
	}
	p*=20;
	for(int i=1;i<=p;++i)wa[i]=0x3f3f3f3f;
	scanf("%d\n",&s);
	int tl;
	for(;s;--s){
		scanf("%s",t);
		tl=strlen(t);
		for(int i=0;i<p;++i){
			char c=st[i+tl];
			st[i+tl]=0;
			if(!strcmp(st+i,t))chkmin(wa[i+1],tl);
			st[i+tl]=c;
		}
	}
	for(int r=1;r<=p;++r){
		for(int l=r;l;--l){
			w[l][r]=w[l+1][r]+(l+wa[l]-1<=r);
		}
	}
	memset(f,-0x3f,sizeof(f));
	f[0][0]=0;
	for(int sc=1;sc<=k;++sc){
		for(int i=1;i<=p;++i){
			for(int j=i;j;--j)chkmax(f[sc][i],f[sc-1][j-1]+w[j][i]);
		}
	}
	printf("%d\n",f[k][p]);

	return 0;
}

