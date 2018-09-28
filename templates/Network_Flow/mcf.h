struct MCF{
	int to[260817],lst[260817],w[260817],beg[192608],c[260817],n,e;
	MCF(){e=1;}
	void add(int u,int v,int wa,int cost){
		to[++e]=v;lst[e]=beg[u];beg[u]=e;c[e]=cost;w[e]=wa;
		to[++e]=u;lst[e]=beg[v];beg[v]=e;c[e]=-cost;w[e]=0;
	}
	int mincost,dis[1926081],flw[1926081],pre[1926081],inq[1926081];
	int q[19260817],*l,*r;
	int spfa(int s,int t){
		for(int i=1;i<=n;++i)dis[i]=0x3f3f3f3f,pre[i]=flw[i]=0;
		flw[s]=0x3f3f3f3f;
		pre[s]=0;
		*(l=r=q)=s;
		dis[s]=0;
		while(l<=r){
			inq[*l]=0;
			for(int i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(dis[to[i]],dis[*l]+c[i])){
				pre[to[i]]=i;
				flw[to[i]]=min(flw[*l],w[i]);
				if(!inq[to[i]]){
					inq[to[i]]=1;
					*(++r)=to[i];
				}
			}
			++l;
		}
		if(!flw[t])return 0;
		int flow=flw[t];
		mincost+=flow*dis[t];
		while(pre[t]){
			s=pre[t];	
			w[s]-=flow;
			w[s^=1]+=flow;	
			t=to[s];
		}
		return flow;
	}
	int Min_Cost_Flow(int s,int t){
		while(spfa(s,t));
		return mincost;
	}
};
