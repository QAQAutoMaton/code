/*
Author: CNYALI_LK
LANG: C++
PROG: 3293.cpp
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
int l[4000005],r[4000005],cnt[4000005],t,rt[204747];
int insert(int rt,int x){
	int ts=++t,ra=t;
	l[ts]=l[rt];
	r[ts]=r[rt];
	cnt[ts]=cnt[rt]+1;
	for(int i=17;~i;--i){
		if(x&(1<<i)){
			rt=r[rt];
			l[++t]=l[rt];
			r[t]=r[rt];
			cnt[t]=cnt[rt]+1;
			r[ts]=t;
			ts=t;
		}
		else{
			rt=l[rt];
			l[++t]=l[rt];
			r[t]=r[rt];
			cnt[t]=cnt[rt]+1;
			l[ts]=t;
			ts=t;
		}
	}
	return ra;
}
int Count(int rt,int x){
	if(x<0)return 0;
	int w=0;
	for(int i=17;rt&&~i;--i)if(x&(1<<i)){
		w+=cnt[l[rt]];
		rt=r[rt];
	}
	else rt=l[rt];
	return w+cnt[rt];
}
int count(int l,int r,int xl,int xr){
	return Count(rt[r],xr)-Count(rt[r],xl-1)-Count(rt[l],xr)+Count(rt[l],xl-1);
}
int main(){
#ifdef cnyali_lk
	freopen("3293.in","r",stdin);
	freopen("3293.out","w",stdout);
#endif
	int n,m,xl,b,x,l,r;
	n=read();m=read();
	for(int i=1;i<=n;++i){
		xl=read();
		rt[i]=insert(rt[i-1],xl);
	}
	for(;m;--m){
		b=read();x=read();l=read()-1;r=read();
		xl=-x;
		for(int i=17;~i;--i){
			if(b&(1<<i)){
				if(!count(l,r,xl,xl+(1<<i)-1))xl+=1<<i;
			}else{
				if(count(l,r,xl+(1<<i),xl+(1<<(i+1))-1))xl+=1<<i;
			}
		}
		printf("%d\n",(xl+x)^b);
	}
	return 0;
}

