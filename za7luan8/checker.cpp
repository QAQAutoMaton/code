#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
const int maxn=70005;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define fi first
#define se second
int n,k,cnt,Type[maxn],anc[19][maxn],M[19][maxn],m[19][maxn],dep[maxn];
pii OriginEdge[maxn];
piii Origin[maxn],OutEdge[maxn];
vector<pii>G[maxn];
inline void Prework(int u=1,int fa=0) {
	for(int i=1;i<19;++i)
		anc[i][u]=anc[i-1][anc[i-1][u]],
		M[i][u]=max(M[i-1][u],M[i-1][anc[i-1][u]]),
		m[i][u]=min(m[i-1][u],m[i-1][anc[i-1][u]]);
	for(int i=0;i<(int)G[u].size();++i) {
		int v=G[u][i].fi,w=G[u][i].se;
		if(v==fa)
			continue;
		anc[0][v]=u,M[0][v]=m[0][v]=w,dep[v]=dep[u]+1;
		Prework(v,u);
	}
}
inline int GetM(int x,int y) {
	if(dep[x]<dep[y])
		swap(x,y);
	int res=0,d=dep[x]-dep[y];
	for(int i=18;~i;--i)
		if(d>>i&1)
			res=max(res,M[i][x]),x=anc[i][x];
	if(x==y)
		return res;
	for(int i=18;~i;--i)
		if(anc[i][x]!=anc[i][y])
			res=max(res,M[i][x]),res=max(res,M[i][y]),x=anc[i][x],y=anc[i][y];
	return max(res,max(M[0][x],M[0][y]));
}
inline int Getm(int x,int y) {
	if(dep[x]<dep[y])
		swap(x,y);
	int res=2e9,d=dep[x]-dep[y];
	for(int i=18;~i;--i)
		if(d>>i&1)
			res=min(res,m[i][x]),x=anc[i][x];
	if(x==y)
		return res;
	for(int i=18;~i;--i)
		if(anc[i][x]!=anc[i][y])
			res=min(res,m[i][x]),res=min(res,m[i][y]),x=anc[i][x],y=anc[i][y];
	return min(res,min(m[0][x],m[0][y]));
}
int main(int argc,char **argv) {
	registerTestlibCmd(argc,argv);
	n=inf.readInt(1,70000);
	memset(m,0x3f,sizeof m);
	for(int i=1,u,v;i<n;++i) {
		u=inf.readInt(1,n);
		v=inf.readInt(1,n);
		if(u>v)
			swap(u,v);
		assert(u!=v);
		OriginEdge[i]=pii(u,v);
	}
	sort(OriginEdge+1,OriginEdge+n);
	k=inf.readInt(1,70000);
	for(int i=1,x,y,z;i<=k;++i) {
		string tmp=inf.readToken();
		x=inf.readInt(1,n);
		y=inf.readInt(1,n);
		z=inf.readInt(1,1000000000);
		if(tmp[0]=='M')
			Origin[++cnt]=piii(pii(x,y),z),Type[cnt]=0;
		else
			Origin[++cnt]=piii(pii(x,y),z),Type[cnt]=1;
	}
	for(int i=1,x,y,z;i<n;++i) {
		x=ouf.readInt(1,n);
		y=ouf.readInt(1,n);
		z=ouf.readInt(1,1000000000);
		if(x>y)
			swap(x,y);
		OutEdge[i]=piii(pii(x,y),z);
	}
	sort(OutEdge+1,OutEdge+n);
	for(int i=1;i<n;++i)
		if(OriginEdge[i].fi!=OutEdge[i].fi.fi||OriginEdge[i].se!=OutEdge[i].fi.se)
			quitf(_wa,"The edges of output are not the same as the edges of input.");
	for(int i=1;i<n;++i)
		G[OutEdge[i].fi.fi].push_back(pii(OutEdge[i].fi.se,OutEdge[i].se)),
		G[OutEdge[i].fi.se].push_back(pii(OutEdge[i].fi.fi,OutEdge[i].se));
	Prework();
	for(int i=1;i<=cnt;++i)
		if(Type[i]) {
			int tmp=Getm(Origin[i].fi.fi,Origin[i].fi.se);
			if(tmp!=Origin[i].se)
				quitf(_wa,"The tree does not satisfy quest %d. The min of path from %d to %d Expected: %d, received :%d\n",i,Origin[i].fi.fi,Origin[i].fi.se,Origin[i].se,tmp);
		}
		else {
			int tmp=GetM(Origin[i].fi.fi,Origin[i].fi.se);
			if(tmp!=Origin[i].se)
				quitf(_wa,"The tree does not satisfy quest %d. The max of path from %d to %d Expected: %d, received :%d\n",i,Origin[i].fi.fi,Origin[i].fi.se,Origin[i].se,tmp);
		}
	quitf(_ok,"The tree satisfies all quests.");
}
