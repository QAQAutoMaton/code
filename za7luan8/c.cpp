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
pii a[127],b[127];
pii operator -(pii a,pii b){return make_pair(a.x-b.x,a.y-b.y);}
int X(pii a,pii b){return a.x*b.y-a.y*b.x;}
int In(pii a,int n,pii *s){
	for(int i=1;i<=n;++i)if(X(s[i]-a,s[i%n+1]-a)<=0)return 0;
	return 1;
}
int Cross(pii al,pii ar,pii bl,pii br){
	if(!(max(al.x,ar.x)>=min(bl.x,br.x) && max(bl.x,br.x)>=min(al.x,ar.x) && max(al.y,ar.y)>=min(bl.y,br.y) && max(bl.y,br.y)>=min(al.y,ar.y)))return 0;
	if((X(bl-al,ar-al)*X(br-al,ar-al))>=-eps)return 0;
	if((X(al-bl,br-bl)*X(ar-bl,br-bl))>=-eps)return 0;
	return 1;
}
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int n,m,no=0;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i)a[i]=make_pair(read(),read());
		m=read();
		for(int i=1;i<=m;++i)b[i]=make_pair(read(),read());
		printf("Case %d:",++no);
		int ok=0;
		for(int i=1;i<=n;++i)
			if(In(a[i],m,b)){ok=1;printf("Yes\n");break;}
		if(ok)continue;
		for(int i=1;i<=m;++i)
			if(In(b[i],n,a)){ok=1;printf("Yes\n");break;}
		if(ok)continue;
		for(int i=1;i<=n && !ok;++i)for(int j=1;j<=m;++j)if(Cross(a[i],a[i%n+1],b[j],b[j%m+1])){printf("Yes\n");ok=1;break;}
		if(!ok)printf("No\n");
	}
	return 0;
}

