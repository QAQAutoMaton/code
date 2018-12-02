// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define RG register
#define MAX 111
#define ft(i) (zt[i].first)
#define sd(i) (zt[i].second)
inline int read()
{
    RG int x=0,t=1;RG char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
int f[MAX][MAX];
int n,m,MC,Day,a[MAX],w[MAX],C[MAX];
struct Node{int i,F,L;};
pair<int,int> zt[1111111];
int tot,mx;
int MOD=1000007;
struct Hash
{
    struct Line{int x,y,next;}e[1111111];
    int h[1000007+1],cnt;
    void Add(int x,int y)
    {
        int pos=(1ll*x*101+y)%MOD;
        e[++cnt]=(Line){x,y,h[pos]};h[pos]=cnt;
    }
    bool Query(int x,int y)
    {
        int pos=(1ll*x*101+y)%MOD;
        for(int i=h[pos];i;i=e[i].next)
            if(e[i].x==x&&e[i].y==y)return true;
        return false;
    }
}Map;
void BFS()
{
    queue<Node> Q;Q.push((Node){1,1,0});
    while(!Q.empty())
    {
        Node u=Q.front();Q.pop();
        if(u.i==Day)continue;
        Q.push((Node){u.i+1,u.F,u.L+1});
        if(u.L>1&&1ll*u.F*u.L<=1ll*mx&&!Map.Query(u.F*u.L,u.i+1))
        {
            Q.push((Node){u.i+1,u.F*u.L,u.L});
            zt[++tot]=make_pair(u.F*u.L,u.i+1);
            Map.Add(u.F*u.L,u.i+1);
        }
    }
}
int main()
{
	Day=100;
	mx=1e8;
    BFS();
	return 0;
	sort(&zt[1],&zt[tot+1]);
    for(int i=1;i<=m;++i)
    {
        if(C[i]<=Day){puts("1");continue;}
        bool fl=false;int mm=1e9;
        for(int j=tot,k=1;j;--j)
        {
            while(k<tot&&ft(k)+ft(j)<=C[i])
                mm=min(mm,sd(k)-ft(k)),++k;
            if(mm+C[i]-ft(j)<=Day-sd(j)){fl=true;break;}
            if(ft(j)<=C[i]&&C[i]-ft(j)<=Day-sd(j)){fl=true;break;}
        }
        fl?puts("1"):puts("0");
    }
    return 0;
}
