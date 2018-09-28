#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
const int MAXK=25,MAXN=1005;
struct Node
{
    int v;
    Node *next;
}*h[MAXN],pool[MAXN*MAXN];//邻接表结构体存图
int tot=0;
void addEdge(int u,int v)
{
    Node *p=&pool[++tot];
    p->v=v; p->next=h[u]; h[u]=p;//建图时建有向边
}
int k,n,num[MAXK],p,a,cnt,cnt2,ans,match[MAXN],tag[MAXN*MAXN];
/*num：每个类型的题目要多少道题
cnt：左侧点的总数
match：二分图匹配用的数组，记录每个点的匹配情况
tag：每个左侧点是由第几个题目类型拆出来的
*/
bool vis[MAXN*MAXN];//二分图匹配使用
vector<int> v[MAXK];//辅助建图
vector<int> res[MAXK];//记录答案
bool dfs(int u)//递归实现二分图匹配
{
    for(Node *p=h[u]; p; p=p->next)
    {
        if(!vis[p->v])
        {
            vis[p->v]=true;
            if(match[p->v]<0 || dfs(match[p->v]))
            {
                match[p->v]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&num[i]);
        cnt+=num[i];//统计左侧点总数
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&p);
        for(int j=1; j<=p; j++)
        {
            scanf("%d",&a);
            v[a].push_back(i);//vector记录每个题目类型都有哪些题
        }
    }
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=num[i]; j++)
        {
            cnt2++;//记录当前左侧点的编号
            tag[cnt2]=i;
            for(int K=0; K<v[i].size(); K++)//注意大小写
            {
                addEdge(cnt2,v[i][K]);
            }
        }
    }
    //二分图匹配
    memset(match,-1,sizeof(match));
    for(int i=1; i<=cnt; i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    if(ans<cnt)
    {
        printf("No Solution!\n");//无解特判
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        res[tag[match[i]]].push_back(i);//存答案
    }
    for(int i=1; i<=k; i++)//做完了，输出
    {
        printf("%d:",i);
        for(int j=0; j<res[i].size(); j++) printf(" %d",res[i][j]);
        printf("\n");
    }
    return 0;
}
