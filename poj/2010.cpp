/*
Author: CNYALI_LK
LANG: C++
PROG: 2010.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<cstdio>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<queue>
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
pii a[192608];
priority_queue<int> p;
int ls[192608],rs[192608];
#define x first
#define y second
int main(){
#ifdef cnyali_lk
	freopen("2010.in","r",stdin);
	freopen("2010.out","w",stdout);
#endif
	int n,c,f;
	n=read();c=read();f=read();
	for(int i=1;i<=c;++i){
		int x=read();
		a[i]=make_pair(x,read());

	}
	sort(a+1,a+c+1);
	n>>=1;
	int s=0;
	for(int i=1;i<=c;++i){
		p.push(a[i].y);
		s+=a[i].y;
		if(i>n){
			s-=p.top();
			p.pop();
		}
		ls[i+1]=i<n?f+1:s;
	}
	while(!p.empty())p.pop();
	s=0;
	for(int i=1;i<=c;++i){
		p.push(a[c-i+1].y);
		s+=a[c-i+1].y;
		if(i>n){
			s-=p.top();
			p.pop();
		}
		rs[c-i]=i<n?f+1:s;
	}
	rs[c]=ls[1]=f+1;
	int i=c;
	while(i&&ls[i]+rs[i]+a[i].y>f){
		--i;
	}
	printf("%d\n",i?a[i].x:-1);
	return 0;
}

