/*
Author: CNYALI_LK
LANG: C++
PROG: 317.cpp
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
char rc(){
	char c;
	while(!isalpha(c=getchar()));
	return c;
}
void rs(char *s){
	while(!isalpha(*s=getchar()))++s;
	while(isalpha(*s))*(++s)=getchar();
	*s=0;
}
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
struct _limit{
	int a,b,ax,bx;
};
_limit a[102424];
char s[102424];
_limit limit(){
	_limit x;
	x.a=read()-1;
	x.ax=rc();
	x.b=read()-1;
	x.bx=rc();
	return x;
}
int h[102424];
int beg[102424],to[233333],lst[233333],dfn[102423],low[102423],no[102423]; 
int blocks,e,t;
void add(int u,int v){
	to[++e]=v;
	lst[e]=beg[u];
	beg[u]=e;
}
int stk[102424],*top=stk;
void dfs(int x){
	dfn[x]=low[x]=++t;
	*(++top)=x;
	for(int i=beg[x];i;i=lst[i])
		if(dfn[to[i]]){
			if(!no[to[i]])
				chkmin(low[x],dfn[to[i]]);
		}else{
			dfs(to[i]);
			chkmin(low[x],low[to[i]]);
		}
	if(dfn[x]==low[x]){
		++blocks;
		do{
			no[*(--top+1)]=blocks;
		}while(*(top+1)!=x);
	}
}

int main(){
#ifdef cnyali_lk
	freopen("317.in","r",stdin);
	freopen("317.out","w",stdout);
#endif
	int n,d,m;
	n=read();
	d=read();
	rs(s);
	int xs=0;
	for(int i=0;i<n;++i){
		if(s[i]=='x'){h[xs]=i;++xs;}
	}
	m=read();
	for(int i=1;i<=m;++i){
		a[i]=limit();
	}
	int un=1<<d,u,v;
	for(int j=0;j<un;++j){
		for(int i=0;i<d;++i)s[h[i]]='a'+!!(j&(1<<i));
		for(int i=0;i<n+n;++i)beg[i]=dfn[i]=low[i]=no[i]=0;
		blocks=e=t=0;	
		for(int i=1;i<=m;++i){
			if(a[i].ax-'A'==s[a[i].a]-'a')continue;
			if(a[i].bx-'A'==s[a[i].b]-'a'){
				int u=a[i].a*2+(a[i].ax-'A'-(a[i].ax-'A'>=s[a[i].a]-'a'));
				add(u,u^1);
			}
			else{
				int u=a[i].a*2+(a[i].ax-'A'-(a[i].ax-'A'>=s[a[i].a]-'a'));
				int v=a[i].b*2+(a[i].bx-'A'-(a[i].bx-'A'>=s[a[i].b]-'a'));
				add(u,v);
				add(v^1,u^1);
			}
		}
		for(int i=0;i<n+n;++i)if(!dfn[i])dfs(i);
		int ok=1;
		for(int i=0;i<n;++i)if(no[i<<1]==no[i<<1|1])ok=0;
		if(ok){
			for(int i=0;i<n;++i){
				int ans=(no[i<<1]>no[i<<1|1]);
				ans+=(ans>=s[i]-'a');
				putchar(ans+'A');
			}
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

