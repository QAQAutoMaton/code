/*
Author: CNYALI_LK
LANG: C++
PROG: 3007.cpp
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
typedef pair<double,double> point;
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
#define x first
#define y second
point p[1926];
double dist(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
point sjx(point p1,point p2,point p3){
	double a=2*(p1.x-p2.x),b=2*(p1.y-p2.y),c=(sqr(p1.x)+sqr(p1.y)-sqr(p2.x)-sqr(p2.y));
	double d=2*(p1.x-p3.x),e=2*(p1.y-p3.y),f=(sqr(p1.x)+sqr(p1.y)-sqr(p3.x)-sqr(p3.y));
	return point((f*b-c*e)/(b*d-a*e),(c*d-a*f)/(b*d-a*e));
}
int notin(point a,point o,double r){
	double s=r*r;
	return (sqr(a.x-o.x)+sqr(a.y-o.y)-s)>eps;

}
/*
a=2(x1-x2) 
b=2(y1-y2)
c=x1^2+y1^2-x2^2-y2^2


d=2(x1-x3) 
e=2(y1-y3)
f=x1^2+y1^2-x3^2-y3^2
*/
/*
x=(fb-ce)/(bd-ae)
y=(cd-af)/(bd-ae)
*/
int main(){
#ifdef cnyali_lk
	freopen("3007.in","r",stdin);
	freopen("3007.out","w",stdout);
#endif
	int n;
	while(n=read()){
		srand(n+19260817);
		double ro=0;
		point O(0,0); 
		for(int i=1;i<=n;++i){
			 scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		random_shuffle(p+1,p+n+1);
		for(int i=1;i<=n;++i)if(notin(p[i],O,ro)){
			O=p[i];
			ro=0;
			for(int j=1;j<i;++j)if(notin(p[j],O,ro)){
				O=make_pair((p[i].x+p[j].x)/2,(p[i].y+p[j].y)/2);
				ro=dist(O,p[i]);
				for(int k=1;k<j;++k)if(notin(p[k],O,ro)){
					O=sjx(p[i],p[j],p[k]);
					ro=dist(O,p[i]);
				}	
			}
		}
		printf("%.2lf %.2lf %.2lf\n",O.x,O.y,ro);
	}
	return 0;
}

