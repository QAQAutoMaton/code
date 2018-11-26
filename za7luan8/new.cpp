#include<bits/stdc++.h>
using namespace std;
void ProcStatus(){
	ifstream f("/proc/self/status");
	cerr<<string(istreambuf_iterator<char>(f),istreambuf_iterator<char>());
}
int czyakioi[100005];
int main(){
	freopen("czy.in","r",stdin);
	freopen("czy.out","w",stdout);
	for(int i=0;i<100005;++i)czyakioi[i]=i;
	ProcStatus();
}

