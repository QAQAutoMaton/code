#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
    int x;
    int y;
    int t;
    int wz;
    bool operator<(node b) const
    {
        if(x/1357==b.x/1357)
        {
            if(y/1357==b.y/1357)
            {
                return t<b.t;
            }
            return y<b.y;
        }
        return x<b.x;
    }
};
node q[65536];
struct change{
    int wz;
    int a;
    int b;
};
change r[65536];
int cntq=0,cntr=0;
int a[65536],vis[1048576];
int ans1[65536];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        char c=getchar();
        while(c!='Q'&&c!='R')
        {
            c=getchar();
        }
        if(c=='Q')
        {
            scanf("%d%d",&q[cntq].x,&q[cntq].y);
            q[cntq].wz=cntq;
            q[cntq].t=cntr;
            cntq++;
        }
        else
        {
            scanf("%d%d",&r[cntr].wz,&r[cntr].b);
            r[cntr].a=a[r[cntr].wz];
            a[r[cntr].wz]=r[cntr].b;
            cntr++;
        }
    }
    sort(q,q+cntq);
    int x=1,y=0,t=cntr;
    int ans=0;
    for(int i=0;i<cntq;i++)
    {
        while(y<q[i].y)
        {
            y++;
            if(vis[a[y]]==0)
            {
                ans++;
            }
            vis[a[y]]++;
        }
        while(x>q[i].x)
        {
            x--;
            if(vis[a[x]]==0)
            {
                ans++;
            }
            vis[a[x]]++;
        }
        while(y>q[i].y)
        {
            vis[a[y]]--;
            if(vis[a[y]]==0)
            {
                ans--;
            }
            y--;
        }
        while(x<q[i].x)
        {
            vis[a[x]]--;
            if(vis[a[x]]==0)
            {
                ans--;
            }
            x++;
        }
        while(t<q[i].t)
        {
            if(r[t].wz>=x&&r[t].wz<=y)
            {
                vis[r[t].a]--;
                if(vis[r[t].a]==0)
                {
                    ans--;
                }
                if(vis[r[t].b]==0)
                {
                    ans++;
                }
                vis[r[t].b]++;
            }
            a[r[t].wz]=r[t].b;
            t++;
        }
        while(t>q[i].t)
        {
            t--;
            if(r[t].wz>=x&&r[t].wz<=y)
            {
                vis[r[t].b]--;
                if(vis[r[t].b]==0)
                {
                    ans--;
                }
                if(vis[r[t].a]==0)
                {
                    ans++;
                }
                vis[r[t].a]++;
            }
            a[r[t].wz]=r[t].a;
        }
        ans1[q[i].wz]=ans;
    }
    for(int i=0;i<cntq;i++)
    {
        printf("%d\n",ans1[i]);
    }
    return 0;
}
