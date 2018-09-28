#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class Subgraphs {
    public:
	char graph[1926][1926];
	char ths[1926];
    vector<string> findGroups(int k) {
		vector<string> vs;
		for(int i=0;i<k+k;++i){
			for(int j=0;j<k+k;++j)graph[i][j]='0';
			graph[i][k+k]=0;
		}
		for(int i=0;i<k;++i){
			for(int j=0;j<i;++j)graph[i][j]=graph[j][i]='1';	
			for(int j=0;j<=i;++j)graph[i][j+k]=graph[j+k][i]='1';
		}
		for(int i=0;i<k+k;++i){
			vs.push_back(graph[i]);
			ths[i]=i<k?'N':'Y';
		}
		int n=k+k;
		ths[n]=0;
		for(int i=0;i<k-1;++i){
			ths[i]='Y';
			ths[i+k]='N';
			vs.push_back(ths);
			for(int j=k+i+1;j>k+1;--j){
				ths[j]='N';
				ths[j-1]='Y';
				vs.push_back(ths);
			}
			ths[k+1]='N';
			ths[n]=0;
		} 
		ths[k-1]='Y';
		ths[n-1]='N';
		vs.push_back(ths);
		return vs;

    }
};

// CUT begin
int main(int argc, char *argv[]) {
	int k;
	cin>>k;
	Subgraphs a;
	vector<string> vs=a.findGroups(k);
	int n=vs[0].length();
	if(vs.size()!=n+(k*(k-1)/2)+1){printf("\033[;031;1mLine number is Incorrect.\033[m\n");return 1;}
	else{
		for(int i=0;i<n;++i){
			if(vs[i].length()!=n){
				printf("\033[;031;1mThe graph is incorrect.\033[m\n");return 1;
			}
			if(vs[i][i]=='1'){printf("\033[;031;1mA point can't link to itself.\033[m\n");return 1;}
			for(int j=0;j<n;++j)if(vs[i][j]!='0'&&vs[i][j]!='1'){printf("\033[;031;1The graph is incorrect.\033[m\n");return 1;}
		}
		for(int i=0;i<=k*(k-1)/2;++i){
			int cnt=0,cntpoi=0;
			for(int j=0;j<n;++j)if(vs[i+n][j]=='Y'){
				++cntpoi;
				for(int k=j+1;k<n;++k)if(vs[i+n][k]=='Y')cnt+=vs[j][k]-'0';
			}
			if(cntpoi!=k){printf("\033[;031;1mThe number of the points in the subgraph Must be %d\033[m\n",k);return 1;}
			if(cnt!=i){printf("\033[;031;1mThe Number of the edges in the subgraph is incorrect\033[m\n");return 1;}
		}
		printf("\033[;032;1mAccepted\033[m\n");
		return 0;
	}

	return 0;
}
// CUT end
