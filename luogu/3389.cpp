#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define up(a,b,c) for (int a(b),end##a(c);a<=end##a;++a)
#define down(a,c,b) for (int a(b),end##a(c);a>=end##a;--a)
#define uup(a,c,b) for (int a(b),end##a(c);a<=end##a;++a)
#define udown(a,b,c) for (int a(b),end##a(c);a>=end##a;--a)
using namespace std;
int read(){
	char s;
	int k=0,base=1;
	while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
	if(s==EOF)exit(0);
	if(s=='-')base=-1,s=getchar();
	while(s>='0'&&s<='9'){
		k=k*10+(s-'0');
		s=getchar();
	}
	return k*base;
}
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
	}
	else{
		if(x/10)write(x/10);
		putchar(x%10+'0');
	}
}
int n;
struct FC{
	double a[128],b;
};
FC fc[233];
void HJ(FC a,FC &b,int c){
	up(i,1,n)a.a[i]*=b.a[c];
	a.b*=b.a[c];
	up(i,1,n)b.a[i]-=a.a[i];
	b.b-=a.b;
}
#define abs(a) ((a)<0?-(a):(a))
int main(){
	n=read();
	up(i,1,n){
		up(j,1,n)cin>>fc[i].a[j];
		cin>>fc[i].b;
	}
	up(i,1,n){
		up(j,i+1,n){
			if(abs(fc[j].a[i])>abs(fc[i].a[i])){
				FC t=fc[i];fc[i]=fc[j];fc[j]=t;
			}
		}
		if(fc[i].a[i]==0){
			printf("No Solution\n");
			return 0;
		}
		double s=fc[i].a[i];
		up(j,1,n)fc[i].a[j]/=s;
		fc[i].b/=s;
		up(j,i+1,n)HJ(fc[i],fc[j],i);
	}
	down(i,1,n){double s=fc[i].a[i];up(j,1,n)fc[i].a[j]/=s;fc[i].b/=s;down(j,1,i-1)HJ(fc[i],fc[j],i);}

	up(i,1,n)printf("%.2lf\n",fc[i].b);
	return 0;
}
