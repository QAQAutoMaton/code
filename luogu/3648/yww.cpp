#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
typedef __int128 lll;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=100010;
int a[N];
int s[N];
ll f[N];
int g[N];
int h[N];
int q[N];
ll gety(int x)
{
	return f[x]+(ll)s[x]*s[x];
}
int getx(int x)
{
	return s[x];
}
ll res;
int mink,maxk;
int n,k;
std::vector<int> c[N];
void gao(ll v,int b)
{
	int head,tail;
	head=1;
	tail=0;
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			f[i]=f[i-1];
			g[i]=g[i-1];
			if(v)
				h[i]=h[i-1];
			else
			{
				h[i]=h[i-1]+1;
				c[i].push_back(i-1);
			}
			continue;
		}
		while(tail>=head+1&&(lll)(gety(i-1)-gety(q[tail]))*(getx(q[tail])-getx(q[tail-1]))<(lll)(gety(q[tail])-gety(q[tail-1]))*(getx(i-1)-getx(q[tail])))
			tail--;
		q[++tail]=i-1;
		int lastg=g[q[head]];
		ll s1,s2;
		while(tail>=head+1&&(s1=gety(q[head+1])-gety(q[head]),s2=(ll)(getx(q[head+1])-getx(q[head]))*2*s[i],s1<=s2))
		{
			if(s1<s2)
			{
				lastg=g[q[head+1]];
				c[i].clear();
			}
			else if(b)
				c[i].push_back(q[head]);
			head++;
		}
		f[i]=f[q[head]]+(ll)(s[i]-s[q[head]])*(s[i]-s[q[head]])+v;
		g[i]=lastg+1;
		h[i]=h[q[head]]+1;
		if(b)
			c[i].push_back(q[head]);
	}
	res=f[n];
	mink=g[n];
	maxk=h[n];
}
void output(int pos,int times,int b)
{
	while(pos&&!a[pos]&&h[pos-1]>=times)
		pos--;
	if(!pos)
		return;
	times--;
	for(auto v:c[pos])
		if(g[v]<=times&&h[v]>=times)
		{
			output(v,times,1);
			if(b)
				printf("%d ",pos);
			return;
		}
	printf("error\n");
}
int main()
{
	open("3648");
	scanf("%d%d",&n,&k);
	k++;
	for(int i=1;i<=n;i++)
	{
		a[i]=rd();
		s[i]=s[i-1]+a[i];
	}
	ll l=0;
	ll r=(ll)s[n]*s[n];
	while(l<r)
	{
		ll mid=(l+r)>>1;
		gao(mid,0);
		if(mink>k)
			l=mid+1;
		else
			r=mid;
	}
	printf("%lld\n",l);
	gao(l,1);
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i];
	ans*=ans;
	ans-=res-(lll)l*k;
	ans/=2;
	printf("%lld\n",ans);
	output(n,k,0);
	return 0;
}
