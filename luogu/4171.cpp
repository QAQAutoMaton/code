/*
Author: CNYALI_LK
LANG: C++
PROG: 4171.cpp
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
int beg[23333],to[23333],lst[23333],sel[23333],e;
int stk[23333],*top;
void add(int u,int v){
	to[++e]=v;
	lst[e]=beg[u];
	beg[u]=e;
}
int read_dish(){
	char c;
	while(!isalpha(c=getchar()));
	if(c=='m')return (read()-1)<<1;
	else return (read()-1)<<1|1;
}
int dfs(int x){
	if(sel[x])return 1;
	if(sel[x^1])return 0;
	sel[*(++top)=x]=1;
	for(int i=beg[x];i;i=lst[i])if(!dfs(to[i]))return 0;	
	return 1;
}
int select(int x){
	top=stk;
	if(dfs(x))return 1;
	do
		sel[*top]=0;
	while((--top)!=stk);
	return 0;
}
int main(){
#ifdef cnyali_lk
	freopen("4171.in","r",stdin);
	freopen("4171.out","w",stdout);
#endif
	int n,m,t,u,v;
	t=read();
	while(t){
		--t;
		n=read();
		m=read();
		for(int i=0;i<n+n;++i)sel[i]=0,beg[i]=0;
		e=0;
		while(m){
			--m;
			u=read_dish();
			v=read_dish();
			add(v^1,u);
			add(u^1,v);
		}
		int check=0;
		for(int i=0;i<n;++i)if(sel[i<<1]||sel[i<<1|1])continue;
		else{
			if(select(i<<1));
			else if(select(i<<1|1));
			else {
				check=1;
				break;
			}
		}
		if(check)printf("BAD\n");
		else {
			printf("GOOD\n");
		}
	}
	return 0;
}

