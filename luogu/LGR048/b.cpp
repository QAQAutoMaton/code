/*
Author: CNYALI_LK
LANG: C++
PROG: b.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s]= in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s]= in LINE %d\n",__FUNCTION__,__LINE__)
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
map<string,int> mp;
char s[102424];
int ri(char *&s){
	++s;
	++s;
	int a=0;
	while(isdigit(*s)){a=a*10+((*s)^48);++s;}
	return a;
}
char ad[102];
char *to_string(char a){
	*ad=a;
	return ad;
}
int main(){
#ifdef cnyali_lk
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	mp["H"]=10;
	mp["C"]=120;
	mp["N"]=140;
	mp["O"]=160;
	mp["F"]=190;
	mp["Na"]=230;
	mp["Mg"]=240;
	mp["Al"]=270;
	mp["Si"]=280;
	mp["P"]=310;
	mp["S"]=320;
	mp["Cl"]=355;
	mp["K"]=390;
	mp["Ca"]=400;
	mp["Mn"]=550;
	mp["Fe"]=560;
	mp["Cu"]=640;
	mp["Zn"]=650;
	mp["Ag"]=1080;
	mp["I"]=1270;
	mp["Ba"]=1370;
	mp["Hf"]=1785;
	mp["Pt"]=1950;
	mp["Au"]=1970;
	mp["Hg"]=2010;
	scanf("%s",s);
	int y=0,l,xb=0;
	for(char *i=s;*i;++i){
		if(*i=='~'){
			xb=1;
			if(isdigit(*(i+1))){
				--i;
				xb=ri(i);
			}
			else ++i;
			i+=5;
			y+=xb*180;
//			printf("H2O %d\n",xb);
		}else
		if(*i=='('){
			l=y;
			y=0;
		}
		else
		if(*i==')'){
			if(*(i+1)=='_'){
				++i;
				y*=ri(i);
			}
			y+=l;
		}
		else{
			string is=to_string(*i);		
			if(islower(*(i+1))){
				++i;
				is+=to_string(*i);
			}
			xb=1;
			if(*(i+1)=='_'){
				++i;

				xb=ri(i);
			}
	//		cout<<is<<' '<<mp[is]<<' '<<xb<<endl;
			y+=xb*mp[is];
		}
	}
	if(y%10)printf("%d.5\n",y/10);
	else printf("%d\n",y/10);
	return 0;
}

