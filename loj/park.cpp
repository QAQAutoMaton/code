#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
#define all(x) x.begin(),x.end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
int n,m,k,p;
vector<int> to[6060606];
vector<pair<int,int> >ato[204848];
int rd[6060606];
int sum[6060606],ok[6060606];
#define x first
#define y second
void aadd(int u,int v,int w){
	ato[u].push_back(make_pair(v,w));
}
typedef pair<int,int> pii;
#define x first
#define y second
int dis[102424],ot[102424];
__gnu_pbds::priority_queue<pii,greater<pii> >pq;
__gnu_pbds::priority_queue<pii,greater<pii> >::point_iterator nod[102424];
void dijkstra(){
    while(!pq.empty())pq.pop();
    for(int i=1;i<=n;++i){dis[i]=0x3f3f3f3f;ot[i]=0;nod[i]=pq.push(make_pair(0x3f3f3f3f,i));}
    dis[1]=0;
	pq.modify(nod[1],make_pair(0,1));
    int x;
    while(!pq.empty()){
        x=pq.top().y;
        pq.pop();
        while(!pq.empty()&&ot[x]){
            x=pq.top().y;
            pq.pop();
        }
        if(ot[x]&&pq.empty())return;
        ot[x]=1;
        for(vector<pair<int,int> >::iterator i=ato[x].begin();i!=ato[x].end();++i){
            if(dis[i->x]>dis[x]+i->y){
				dis[i->x]=dis[x]+i->y;
                pq.modify(nod[i->x],make_pair(dis[i->x],i->x));
            }
        }
    }
}
void add(int u,int v) {to[u].push_back(v),++rd[v];}
int q[6060606];
void Topsort(){
    int l,r,s;	
    l=1;r=0;
    for(int i=1;i<=(k+1)*n;++i)if(!rd[i])q[++r]=i,q[r];
    sum[1]=1;
    while(l<=r){
        s=q[l];
        ++l;
        for(vector<int>::iterator i=to[s].begin();i!=to[s].end();++i){
            sum[*i]+=sum[s];

            if(sum[*i]>=p)sum[*i]-=p;
            ok[*i]=1;
            if(!(--rd[*i]))q[++r]=*i;
        }
    }
}
int read(){
    int s=0;
    char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c)){s=s*10+c-'0';c=getchar();}
    return s;
}
int main(){
#ifdef cnyali_lk
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
#endif
    int t,u,v,w;
    scanf("%d",&t);
    while(t){
        --t;
        n=read();m=read();k=read();p=read();
        for(int i=1;i<=n*(k+1);++i){sum[i]=rd[i]=0;to[i].erase(all(to[i]));}
        for(int i=1;i<=n;++i)ato[i].erase(all(ato[i]));
        for(int i=1;i<=m;++i){
            u=read();v=read();w=read();
            aadd(u,v,w);
        }
		debug("hhpupil %.6lf\n",clock()/1e6);
        dijkstra();
		debug("hhpupil %.6lf\n",clock()/1e6);
        for(int i=1;i<=n;++i)for(int aq=0;aq<=k;++aq)for(vector<pair<int,int> >::iterator j=ato[i].begin();j!=ato[i].end();++j){
            int l=dis[i]+j->y-dis[j->x];
			if(l+aq<=k)add(i+aq*n,j->x+(aq+l)*n);
        }
		debug("hhpupil %.6lf\n",clock()/1e6);
        Topsort();
		debug("hhpupil %.6lf\n",clock()/1e6);
        int ans=0;
        for(int i=0;i<=k;++i){
            if(ok[(i+1)*n]&&rd[(i+1)*n]){ans=-1;break;}
            ans=ans+sum[(i+1)*n];
            if(ans>=p)ans-=p;
        }
        printf("%d\n",ans);
		debug("hhpupil %.6lf\n",clock()/1e6);
    }
    return 0;
}
