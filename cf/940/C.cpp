/*
Author: CNYALI_LK
LANG: C++
PROG: C.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int read(){
	int s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
char s[192608];
void get_(char *s){
	while(!isalpha(*s=getchar()));
	while(isalpha(*s))*(++s)=getchar();
	*s=0;
}
int cnt[27];
char fa[192608];
int JS(int pos,int k){
	if(!s[pos]){
		int i;
		for(i=0;!cnt[i];++i);
		while(pos<k){fa[pos]=i+'a';
			++pos;
		}

		fa[pos]=0;
		return 1;
	}
	if(pos==k-1){
		int i=s[pos]-'a'+1;
		while(i<26&&!cnt[i])++i;
		if(i<26){
			fa[pos]=i+'a';
			fa[pos+1]=0;
			return 1;
		}
		else return 0;
	}
	else{
		int sg=JS(pos+1,k);
		if(sg){
			fa[pos]=s[pos];
			return 1;
		}
		else{
			int i=s[pos]-'a'+1;
			while(i<26&&!cnt[i])++i;
			if(i<26){
				fa[pos]=i+'a';
				i=0;
				while(!cnt[i])++i;
				while(++pos<k)fa[pos]=i+'a';
				fa[pos+1]=0;
				return 1;
			}
			else return 0;
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n,k;
	n=read();k=read();
	get_(s);
	for(int i=0;s[i];++i)cnt[s[i]-'a']=1;
	JS(0,k);
	printf("%s\n",fa);
	return 0;
}

