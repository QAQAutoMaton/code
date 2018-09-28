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
int a[292608];
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int n;
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();

	if(n==1)printf("YES\n1 %d\n",a[1]);
	else{
		int yes=1;
		for(int i=1;i<n;++i)
			if(a[i]==a[i+1])yes=0;
		if(!yes)printf("NO\n");
		else{
			int is=1;
			for(int i=1;i<n;++i){
				if(abs(a[i]-a[i+1])!=1)is=0;
			}
			if(is){
				int ans=0;
				for(int i=1;i<=n;++i)chkmax(ans,a[i]);
				printf("YES\n1 %d\n",ans);
			}
			else{
				for(int i=1;i<=n;++i)--a[i];
				int equ=0;
				for(int i=1;i<n;++i)if(abs(a[i]-a[i+1])!=1){
					if(!equ)equ=abs(a[i]-a[i+1]);
					else if(equ!=abs(a[i]-a[i+1]))yes=0;
				}
				if(yes){
					for(int i=1;i<n;++i)if(abs(a[i]-a[i+1])==1)if(a[i]/equ!=a[i+1]/equ)yes=0;
					if(yes){
						printf("YES\n");
						int ans=0;
						for(int i=1;i<=n;++i)chkmax(ans,a[i]/equ+1);
						printf("%d %d\n",ans,equ);
					}
					else printf("NO\n");
				}
				else printf("NO\n");
			}
		}		
	}
	return 0;
}

