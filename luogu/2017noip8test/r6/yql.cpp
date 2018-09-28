#include<bits/stdc++.h>
#define ll long long
#define eps 1e-8
#define inf 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
const int maxn=200010;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int read(){
    int f=1,x=0;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return f*x;
}
int n,m,bl;
int a[maxn],b[110][2100],s[2100],tl[2100],tr[2100],pos[maxn];

inline int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
inline void change(int x,int y,int z){
    if (x<=bl){
        for (register int i=y;i<=x;++i)b[x][i]=add(b[x][i],z);
    }else{
        for (register int i=y;i<=n;i+=x)a[i]=add(a[i],z),s[pos[i]]=add(s[pos[i]],z);
    }
}

inline int query(int l,int r){
    int ret=0,x;
    if (pos[l]>=pos[r]-1){
        for (register int i=l;i<=r;++i)ret=add(ret,a[i]);
    }else{
        if (l>=(tl[pos[l]]+tr[pos[l]]>>1)){
            for (register int i=l;i<=tr[pos[l]];++i)ret=add(ret,a[i]);
        }else{
            ret=s[pos[l]];
            for (register int i=tl[pos[l]];i<l;++i)ret=(ret-a[i])%MOD;
        }
        if (r<=(tl[pos[r]]+tr[pos[l]]>>1)){
            for (register int i=tl[pos[r]];i<=r;++i)ret=add(ret,a[i]);
        }else{
            ret=(ret+s[pos[r]])%MOD;
            for (register int i=r+1;i<=tr[pos[r]];++i)ret=(ret-a[i])%MOD;
        }
        for (register int i=pos[l]+1;i<pos[r];++i)ret=add(ret,s[i]);
    }
    --l;
    for (register int i=1;i<=bl;++i){
        x=r/i-l/i;
        ret=(ret+1ll*x*b[i][i]%MOD+b[i][r%i]-b[i][l%i])%MOD;
    }
    return (ret+MOD)%MOD;
}

int main(){
    n=read();m=read();
    bl=(int)sqrt(n/18);
    for (register int i=1;i<=n;++i)pos[i]=(i+bl-1)/bl;
    for (register int i=1;i<=n;++i)a[i]=read();
    for (register int i=1;i<=n;++i)s[pos[i]]=(s[pos[i]]+a[i])%MOD;
    for (register int i=1;i<=pos[n];++i)tl[i]=tr[i-1]+1,tr[i]=tr[i-1]+bl;
    tr[pos[n]]=n;
    int op,x,y,z;
    while (m--){
        op=read();
        if (op==1){
            x=read();y=read();z=read();
            change(x,y,z);
        }else{
            x=read();y=read();
            printf("%d\n",query(x,y));
        }
    }
}
