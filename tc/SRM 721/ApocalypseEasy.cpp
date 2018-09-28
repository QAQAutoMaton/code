/*
Author: CNYALI_LK
LANG: C++
PROG: ApocalypseEasy.cpp
Mail: cnyalilk@vip.qq.com
*/

#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<class Ta,class Tb>int chkmin(Ta &a,Tb b){return a>b?a=b,1:0;}
template<class Ta,class Tb>int chkmax(Ta &a,Tb b){return a<b?a=b,1:0;}

class ApocalypseEasy {
    public:
	int to[192608],lst[192608],beg[128],w[192608],e,cur[128],n;
	void add(int u,int v,int wa){
//		if(wa)printf("%d->%d(%d)\n",u,v,wa);
		to[++e]=v;
		lst[e]=beg[u];
		beg[u]=e;
		w[e]=wa;
	}
	vector<int> graph[128];
	int ok[128],vis[128];
	void dfs(int x,int t){
		if(vis[x])return;
		vis[x]=1;
		if(!t)return ;
		for(auto i:graph[x])dfs(i,t-1);
	}
	int dis[128];
	int q[128],*l,*r;
	int bfs(int s,int t,int n){
		for(int i=0;i<n;++i)cur[i]=beg[i];	
		for(int i=0;i<n;++i){dis[i]=0x3f3f3f3f;}
		*(l=r=q)=s;
		dis[s]=0;
		while(l<=r){
			for(int i=beg[*l];i;i=lst[i])if(w[i]&&dis[to[i]]==0x3f3f3f3f){
				dis[to[i]]=dis[*l]+1;
				*(++r)=to[i];
			}
			++l;
		}
		return dis[t]!=0x3f3f3f3f;
	}
	int dfs(int s,int t,int flow){
		if(!flow)return 0;
//		debug("hh??%d,%d,%d\n",s,t,flow);
		if(s==t)return flow;
		for(;cur[s];cur[s]=lst[cur[s]])if(w[cur[s]]){

			int i=cur[s];
			if(dis[s]+1==dis[to[i]]){
				int g=dfs(to[i],t,min(flow,w[i]));
				if(g){
					w[i]-=g;
					w[i^1]+=g;
					return g;
				}
			}
		}
		return 0;
	}
	int dinic(int s,int t,int n){
		int ans=0,flow;
		while(bfs(s,t,n)){
			while(flow=dfs(s,t,0x3f3f3f3f))ans+=flow;
		}
		return ans;
	}
    int maximalSurvival(vector<int> p, vector<int> position, int t) {
		++e;
		int n=p.size(),m=position.size();
		for(int i=0;i<n;++i)graph[i+1].push_back(p[i]),graph[p[i]].push_back(i+1);
		++n;
		for(int i=0;i<n;++i)ok[i]=1;
		for(int i=0;i<m;++i){
			ok[position[i]]=0;
		}
		for(int i=0;i<n;++i)if(!ok[i]){
			add(n,i,1);add(i,n,0);
		}else{
			add(i,n+1,1);add(n+1,i,0);
		}
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j)vis[j]=0;
			dfs(position[i],t);
			for(int j=0;j<n;++j)if(vis[j]&&ok[j]){
				add(position[i],j,1);
				add(j,position[i],0);
			}
		}
        return dinic(n,n+1,n+2);
    }
};

// CUT begin
ifstream data("ApocalypseEasy.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> p, vector<int> position, int t, int __expected) {
    time_t startClock = clock();
    ApocalypseEasy *instance = new ApocalypseEasy();
    int __result = instance->maximalSurvival(p, position, t);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> p;
        from_stream(p);
        vector<int> position;
        from_stream(position);
        int t;
        from_stream(t);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, position, t, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1520075861;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ApocalypseEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
