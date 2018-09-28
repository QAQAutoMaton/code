#include<cstdio>
#include<cstring>
#define debug(...) fprintf(stderr,__VA_ARGS__)
int p[40000009];
int seed, n, k, S;
int getrand()
{
	seed = ((seed * 12321) ^ 9999) % 32768;
	return seed;
}
void generateData()
{
	scanf("%d%d%d",&k,&seed,&S);
	int t = 0;
	n = k * 2 + 1;
	memset(p, 0, sizeof(p));
	for (int i = 1; i <= n; i++)
	{
		p[i] = (getrand() / 128) % 2;
		t += p[i];
	}
	int i = 1;
	while (t > k)
	{
		while (p[i] == 0)
			i++;
		p[i] = 0;
		t--;
	}
	while (t < k)
	{
		while (p[i] == 1)
			i++;
		p[i] = 1;
		t++;
	}
	for(int i=1;i<=n;++i)p[i+n]=p[i];
}
int cnt[40000009],f[20000005],line,ans;
int fi[20000005],ians;
void add(int a,int b){
	f[a]+=b;
	if(a>line)ans+=b;
}
void iadd(int a,int b){
	fi[a]+=b;
	if(a<line)ians+=b;
}
int count(int a){
	while(line<a){
		ians+=fi[line];
		ans-=f[++line];
	}
	while(a<line){
		ans+=f[line];
		ians-=fi[--line];
	}
	return ans;
}

int icount(int a){
	while(line<a){

		ians+=fi[line];
		ans-=f[++line];
	}
	while(a<line){
		ans+=f[line];
		ians-=fi[--line];
	}
	return ians;
}
int main()
{
#ifdef cnyali_lk
	freopen("cipher.in","r",stdin);
	freopen("cipher.out","w",stdout);
#endif
	generateData();
	cnt[0]=10000000;
	for(int i=1;i<=n+n;++i){
		cnt[i]=cnt[i-1];
		if(p[i])++cnt[i];
		else --cnt[i];
	}
	
	line=10000000;
	int ans1=0,ans2=0,ans3=0;
	for(int i=1;i<n+n;++i){
		if(p[i])
		add(cnt[i],1);
		else iadd(cnt[i],1);
		if(i>=n){
			if(p[i-n+1])add(cnt[i-n+1],-1);
			else{
				iadd(cnt[i-n+1],-1);
				if(count(cnt[i-n+1])==0)ans1=(i-n+1);
				if(count(cnt[i-n+1])==S)ans2=(i-n+1);
				if(icount(cnt[i-n+1])==S)ans3=(i-n+1);
			}
		}
	}
	printf("%d\n%d\n%d\n",ans1,ans2,ans3);

	return 0;
}
