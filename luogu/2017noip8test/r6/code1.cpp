#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=200005,BLO=3000;
int n,m,x,y,z,blo,mod=1000000007,belong[N],LL[BLO],RR[BLO];
long long bsum[BLO][BLO],sum[N],bbb[BLO],b[N],block[BLO];
inline int ask(int l,int r){
    long long ans=0;
    int L=belong[l],R=belong[r];
    if(L==R){
        for(int i=l;i<=r;i++){ans+=b[i]; }
        return ans%mod;
    }
    for(int i=L+1;i<R;i++){ans+=block[i];}
    for(int i=l;i<=RR[L];i++){ans+=b[i];}
    for(int i=LL[R];i<=r;i++){ans+=b[i];}
    return ans%mod;
}
inline int solve(int x,int y){
    long long ans=0;
    for(int i=1;i<blo;i++){
        ans+=bbb[i]*((x/i)-(y/i))+bsum[i][x%i]-bsum[i][y%i];
    }
    return ans%mod;
}
int main(){
    n=read(); m=read();
    int t=n/6;
    if(t>100)blo=sqrt(n/10); else blo=sqrt(n);
    for(int i=1;i<=n;i++)belong[i]=(i-1)/blo+1;
    for(int i=1;i<=n;i++){
        RR[belong[i]]=i;
        if(!LL[belong[i]])LL[belong[i]]=i;
    }
    belong[n+1]=n/blo+1;
    for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+read())%mod;
    while(m--){
        int op=read();
        if(op==1){
            x=read(); y=read(); z=read();
            if(x>=blo){
                for(int i=y;i<=n;i+=x){
                    b[i]+=z;  block[belong[i]]+=z;
                }
            }else{
                bbb[x]+=z;
                for(int i=y;i<=x;i++){bsum[x][i]+=z; }
            }
        }else{
            int l=read(),r=read(),ans=((long long)sum[r]-sum[l-1]+mod)%mod;
            ans=(ans+ask(l,r))%mod;
            ans=((long long)ans+solve(r,l-1)+mod+mod)%mod;
            writeln(ans);
        }
    }
}
