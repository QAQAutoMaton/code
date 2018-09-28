/*
Author: CNYALI_LK
LANG: C++
PROG: FFT.cpp
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
typedef complex<double> fs;
fs a[333333],b[333333],c[333333]; 
int s,rev[333333];
void FFT(fs *a,int flag){
	for(int i=0;i<s;++i)if(i<rev[i])swap(a[i],a[rev[i]]);	
	for(int i=1;i<s;i<<=1){
		fs wa(cos(pi/i),flag*sin(pi/i));
		for(int j=0;j<s;j+=i+i){
			fs w(1,0),u,v;
			for(int k=0;k<i;++k){
				u=a[j+k],v=w*a[j+k+i];
				a[j+k]=u+v;
				a[j+k+i]=u-v;
				w=w*wa;
			}
		}
	}
	if(flag<0){
		for(int i=0;i<s;++i)a[i]/=s;
	}
}
int main(){
#ifdef cnyali_lk
	freopen("FFT.in","r",stdin);
	freopen("FFT.out","w",stdout);
#endif
	int n,m;
	n=read();
	m=read();
	for(int i=0;i<=n;++i)a[i]=read();
	for(int j=0;j<=m;++j)b[j]=read();
	for(s=1;s<=n+m;s<<=1);
	for(int i=1;i<s;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(s>>1));
	FFT(a,1);
	FFT(b,1);
	for(int i=0;i<s;++i)c[i]=a[i]*b[i];
	FFT(c,-1);
	for(int i=0;i<=n+m;++i)cout<<(int)(c[i].real()+0.01)<<' ';
	return 0;
}

