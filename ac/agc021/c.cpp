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
char s[1024][1024];
int g[1926];
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int n,m,a,b,an,am;
	an=n=read();am=m=read();a=read();b=read();

	if((n&m&1))printf("NO\n");
	else{
		if(n&1){
			if(a<m/2){printf("NO\n");return 0;}
			else{
				a-=m/2;
				for(int i=1;i<=m;++i)s[n][i]=i&1?'<':'>';
				--n;
			}
		}
		if(m&1){
			if(b<n/2){printf("NO\n");return 0;}
			else{
				b-=n/2;
				--m;
				for(int i=1;i<=n;++i)s[i][m]=i&1?'<':'>';
			}	
		}
		if((a+b)<<1>n*m)printf("NO\n");
		else{
			int t=n*m/4;
			memset(g,-1,sizeof(g));
			for(int i=1;i<=(n+1)/2;++i){
				g[i]=1;
				if(i*2<=n)g[i]|=2;
			}
			for(int j=1;j<=(m+1)/2;++j){
				g[j+(n+1)/2]=0;
				if(j*2<=m)g[j+(n+1)/2]|2;
			
			}
			int ax=0,ay=0;
			for(int i=1;i<=t;++i){
				if(~g[i]){
					s[ax*2+1][ay*2+1]='.';
					s[ax*2+2][ay*2+1]='.';
					s[ax*2+1][ay*2+2]='.';
					s[ax*2+2][ay*2+2]='.';
				}
				if(g[i]&1){
					s[ax*2+1][ay*2+1]='<';
					s[ax*2+1][ay*2+2]='>';
					if(g[i]&2){
					s[ax*2+2][ay*2+1]='<';
					s[ax*2+2][ay*2+2]='>';
					}
					else{
					s[ax*2+2][ay*2+1]='.';
					s[ax*2+2][ay*2+2]='.';
					}
				}	
				else{
					s[ax*2+1][ay*2+1]='^';
					s[ax*2+2][ay*2+1]='v';
					if(g[i]&2){
						s[ax*2+1][ay*2+2]='^';
						s[ax*2+2][ay*2+2]='v';
					}
					else{
						s[ax*2+1][ay*2+2]='.';
						s[ax*2+2][ay*2+2]='.';
					}
				}
				++ay;
				if(ay>=(m/2)){
					ay=0;++ax;
				}
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=an;++i,putchar('\n'))for(int j=1;j<=am;++j)putchar(s[i][j]);
	return 0;
}

