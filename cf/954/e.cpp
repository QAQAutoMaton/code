/*
Author: CNYALI_LK
LANG: C++
PROG: e.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char WritellBuffer[1024];
template<class T>void write(T a,char end){
	ll cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WritellBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WritellBuffer[cnt]);--cnt;}
	putchar(end);
}
ll a[292606];
pii s[192608];
#define x first
#define y second
int main(){
#ifdef cnyali_lk
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	ll n=read(),t=read();
	for(ll i=1;i<=n;++i){
		a[i]=read();
	}
	for(ll i=1;i<=n;++i)s[i]=make_pair(read(),a[i]);
	sort(s+1,s+n+1);
	double tot1=0,tot2=0;
	for(ll i=1;i<=n;++i){
		tot1+=s[i].x*s[i].y;
		tot2+=s[i].y;
	}
	double temp=tot1/tot2;

	if(fabs(temp-t)<=eps)printf("%.15lf",tot2);
	else{
		if(temp>t){
			for(ll i=n;i&&temp-t>eps;--i){
				if((tot1-s[i].x*s[i].y)>eps+t*(tot2-s[i].y)){
					tot1-=s[i].x*s[i].y;
					tot2-=s[i].y;
					if(tot2<eps)temp=0;
					else
					temp=tot1/tot2;
				}
				else{
					double ans=(t*tot2-tot1)/(t-s[i].x);
					tot2-=ans;
					break;
				}
			}
			printf("%.15lf\n",tot2);
		}
		else{
			for(ll i=1;temp-t<-eps;++i){
				if((tot1-s[i].x*s[i].y)<-eps+t*(tot2-s[i].y)){
					tot1-=s[i].x*s[i].y;
					tot2-=s[i].y;
					if(tot2<eps)temp=0;
					else
					temp=tot1/tot2;
				}
				else{
					double ans=(t*tot2-tot1)/(t-s[i].x);
					tot2-=ans;

					break;
				}
			}
			printf("%.15lf\n",tot2);
		}
	}
	return 0;
}
