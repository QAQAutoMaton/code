/*
Author: CNYALI_LK
LANG: C++
PROG: odd.cpp
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
typedef int ll;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;} template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
const int bufl=1<<22;
char bufi[bufl],*inf=bufi;
char bufo[bufl],*ouf=bufo;

int read(){
    int k=0;
    while(!isdigit(*inf))++inf;
    while(isdigit(*inf)){
        k=k*10+(*inf-'0');
        ++inf;
    }
    return k;
}
void writeint(int x){
    if(x/10)writeint(x/10);
    *ouf=x%10+'0';
    ++ouf;
}
const ll N=131072,gkk=60,M=262144;
const ll primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281};
const ll inv[]={9980997,13307996,7984798,11406854,14517814,18426456,9393880,5253157,16490343,8260136,2575742,18343454,3895024,17640832,1698894,3013132,7443456,4581442,9236147,18275065,6562848,2779519,7936697,4037258,6379607,19566707,13566404,4104336,3662752,13602421,16661192,1219054,13259427,9047523,3751248,8196316,14621843,1714528,12192356,11884887,8029406,13455046,17976246,13342473,14084859,15548287,10217514,9846724,5364237,3486812,1627803,14950615,1076789,12406658,19340609,8652728,7791857,7955334,1657495,8808852};
const ll p=19961993;
ll mul[M+233];
long long appear[M+233];
void Change(ll x,ll y){
	x+=N;
	mul[x]=y;
	appear[x]=0;
	for(ll i=0;i<60;++i)if(!(y%primes[i]))appear[x]|=(1LL<<i);
	for(x>>=1;x;x>>=1){mul[x]=(long long )mul[x<<1]*mul[x<<1|1]%p;appear[x]=appear[x<<1]|appear[x<<1|1];}
}
ll Phi(ll l,ll r){
	l+=N;r+=N;
	ll prod=1;
	long long app=0;
	while(l<r){
		if(l&1){
			prod=(long long )prod*mul[l]%p;
			app|=appear[l];
			++l;
		}
		if(!(r&1)){
			prod=(long long )prod*mul[r]%p;
			app|=appear[r];
			--r;
		}
		l>>=1;r>>=1;
	}
	if(l==r){prod=(long long )prod*mul[l]%p;app|=appear[l];}
	for(ll i=0;i<60;++i)if(app&(1LL<<i))prod=(long long)prod*inv[i]%p;
	return prod;
}
int main(){
#ifdef cnyali_lk
	freopen("odd.in","r",stdin);
	freopen("odd.out","w",stdout);
#endif
	fread(bufi,1,bufl,stdin);
	ll n,x,y;	
	n=read();
	for(ll i=0;i<100000;++i){mul[i+N]=3;appear[i+N]=2;}
	for(ll i=100000;i<N;++i)mul[i+N]=1;
	for(ll i=N-1;i;--i){
		mul[i]=(long long )mul[i<<1]*mul[i<<1|1]%p;
		appear[i]=appear[i<<1]|appear[i<<1|1];
	}
	for(;n;--n){
		if(read()){
			x=read()-1;y=read();
			Change(x,y);
		}
		else{
			x=read()-1;y=read()-1;
			writeint(Phi(x,y));
			*ouf='\n';
			++ouf;
		}
	}
	fwrite(bufo,1,ouf-bufo,stdout);
	return 0;
}

