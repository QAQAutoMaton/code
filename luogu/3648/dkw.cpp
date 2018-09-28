#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
#define LD long double
using namespace std;
inline void read(int &x){
    char ch=' ';
    while(ch<'0' || ch>'9')ch=getchar();
    while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
const int N=1e5+5,K=205;
vector<int> c[N];
int n,k,a[N];
LL sum[N];
int q[N],L,R;
LL dp[N],mn[N],mx[N],mn2[N],mx2[N];
inline bool check(int a,int b,int c){
	LD k1=2e18,k2=2e18;
    if(sum[b]!=sum[a])k1=(LD)(dp[b]-sum[b]*sum[b]-dp[a]+sum[a]*sum[a])/(LD)(sum[b]-sum[a]);
	if(sum[c]!=sum[b])k2=(LD)(dp[c]-sum[c]*sum[c]-dp[b]+sum[b]*sum[b])/(LD)(sum[c]-sum[b]);
    if(k1<k2)return 1;
    else return 0;
}
inline bool check2(int a,int b,LL v){
    LD k1=(LD)(dp[b]-sum[b]*sum[b]-dp[a]+sum[a]*sum[a])/(LD)(sum[b]-sum[a]);
    if(k1>=v){
        if(fabs(k1-v)<1e-8)
            mn2[b]=min(mn2[a],mn2[b]),mx2[b]=max(mx2[a],mx2[b]);
        return 1;
    }
    else return 0;
}
inline void print(int pos,int times,int flag){
    while(pos && !a[pos] && mx[pos-1]>=times)pos--;
    if(!pos)
        return;
    times--;
    for(vector<int>::iterator it=c[pos].begin();it!=c[pos].end();++it){
        int x=*it;
        if(mn[x]<=times && times<=mx[x]){
            print(x,times,1);
            break;
        }
    }
    if(flag)printf("%d ",pos);
}
int main(){
	freopen("3648.in","r",stdin);
	freopen("3648.ans","w",stdout);
    read(n);read(k);++k;
    for(int i=1;i<=n;++i)read(a[i]);
    for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
    LL l=0,r=sum[n]*sum[n],mid;
    while(l<r){
        mid=(l+r)>>1;
        L=1;R=0;
        for(int i=1;i<=n;++i){
            if(L>R){
                if(!a[i]){
                    dp[i]=dp[i-1];
                    mn[i]=mn[i-1];
                    mn2[i]=mn[i];
                }
                else{
                    dp[i]=-mid;
                    mn[i]=1;
                    mn2[i]=mn[i];
                    while(L<R && check(q[R-1],q[R],i))R--;
                    q[++R]=i;
                }
            }
            else{
                if(!a[i]){
                    dp[i]=dp[i-1];
                    mn[i]=mn[i-1];
                    mn2[i]=mn[i];
                }
                else{
                    mn2[q[L]]=mn[q[L]];
                    while(L<R && check2(q[L],q[L+1],-sum[i]))L++;
                    dp[i]=dp[q[L]]+sum[q[L]]*(sum[i]-sum[q[L]])-mid;
                    mn[i]=mn2[q[L]]+1;
                    mn2[i]=mn[i];
                    if(-mid>=dp[i]){
                        dp[i]=-mid;
                        mn[i]=mn2[i]=1;
                    }
                    while(L<R && check(q[R-1],q[R],i))R--;
                    q[++R]=i;
                }
            }
        }
        if(mn[n]>k)l=mid+1;
        else r=mid;
    }
    mid=l;
    L=1;R=0;
    for(int i=1;i<=n;++i){
        if(L>R){
            if(!a[i]){
                dp[i]=dp[i-1];
                mn[i]=mn[i-1];
                mn2[i]=mn[i];
				if(!mid)c[i].push_back(i-1),mx[i]=mx[i-1]+1;
				else mx[i]=mx[i-1];
                mx2[i]=mx[i];
				while(L<R && check(q[R-1],q[R],i))R--;
                q[++R]=i;
            }
            else{
                c[i].push_back(0);
                dp[i]=-mid;
                mn[i]=1;
                mn2[i]=mn[i];
                mx[i]=1;
                mx2[i]=mx[i];
                while(L<R && check(q[R-1],q[R],i))R--;
                q[++R]=i;
            }
        }
        else{
            if(!a[i]){
                dp[i]=dp[i-1];
                mn[i]=mn[i-1];
                mn2[i]=mn[i];
                if(!mid)c[i].push_back(i-1),mx[i]=mx[i-1]+1;
				else mx[i]=mx[i-1];
                mx2[i]=mx[i];
				while(L<R && check(q[R-1],q[R],i))R--;
                q[++R]=i;
            }
            else{
                mn2[q[L]]=mn[q[L]];
                mx2[q[L]]=mx[q[L]];
                while(L<R){
                    int a=q[L],b=q[L+1];
                    LD k1;
					if(sum[b]!=sum[a])k1=(LD)(dp[b]-sum[b]*sum[b]-dp[a]+sum[a]*sum[a])/(LD)(sum[b]-sum[a]);
					else k1=2e18;
                    if(k1>-sum[i]){
                        c[i].clear();
                        ++L;
                    }
                    else if(k1==-sum[i]){
                        mn2[b]=min(mn2[a],mn2[b]),mx2[b]=max(mx2[a],mx2[b]);
                        c[i].push_back(a);
                        ++L;
                    }
                    else break;
                }
                c[i].push_back(q[L]);
                dp[i]=dp[q[L]]+sum[q[L]]*(sum[i]-sum[q[L]])-mid;
                mn[i]=mn2[q[L]]+1;
                mx[i]=mx2[q[L]]+1;
                mn2[i]=mn[i];
                mx2[i]=mx[i];
                if(-mid>dp[i]){
                    dp[i]=-mid;
                    mx2[i]=mx[i]=mn[i]=mn2[i]=1;
                    c[i].clear();
                    c[i].push_back(0);
                }
				else if(-mid==dp[i])mn[i]=mn2[i]=1,c[i].push_back(0);
                while(L<R && check(q[R-1],q[R],i))R--;
                q[++R]=i;
            }
        }
    }
    printf("%lld\n",(long long)(dp[n]+k*mid));
	for(int i=1;i<=n;++i)printf("%d %d\n",mn[i],mx[i]);
    print(n,k,0);
    return 0;
}
