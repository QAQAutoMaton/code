/*
Author: CNYALI_LK
LANG: C++
PROG: h.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
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
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
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
int talk[205][205],he[205][205],per=0,hehe=0,tot=0,cnt;
tr1::unordered_map<string,int> mp;
char s[1023],*t;
int my_gets(){
	char c;
	int fr,to;
	t=s;
	while((c=getchar()) && c!='\n' && c!=EOF && c!='-'){
		*t=c;++t;
	}
	if(!c || c=='\n' || c==EOF)return 0;
	*t=0;
//	printf("%s\n",s);
	fr=!mp.count(s)?mp[s]=++tot:mp[s];
//	printf("%d\n",fr);
	c=getchar();
	t=s;
	while((c=getchar()) && c!='\n' && c!=EOF && c!=':'){
		*t=c;++t;
	}
	*t=0;
//	printf("%s\n",s);
	to=!mp.count(s)?mp[s]=++tot:mp[s];
//	printf("%d\n",to);
	if(fr>to)swap(fr,to);
	if(!talk[fr][to]){++cnt;talk[fr][to]=1;}
	hehe-=he[fr][to];
	he[fr][to]=0;
	c=getchar();
	while(c!='\n'){
		t=s;
		int len=0,ish=1;
		while(isalpha(c=getchar())){
			if(c<='Z')c=c+'a'-'A';
			++len;
			if(((len&1)&&(c!='h')) ||(!(len&1) && c!='e'))ish=0;
		}
		if(len&1||len<4)ish=0;
		if(ish)he[fr][to]=1;
	}
	*t=0;
	hehe+=he[fr][to];
	return 1;
}
int main(){
#ifdef cnyali_lk
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
#endif	
	while(my_gets());
//	printf("%lf\n",100.*hehe/cnt);
	printf("%d%%\n",(int)(100.*hehe/cnt+0.5));
	return 0;
}

