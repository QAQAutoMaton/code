/*
Author: CNYALI_LK
LANG: C++
PROG: Apocalypse.cpp
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

class Apocalypse {
    public:
	int to[192608],lst[192608],w[192608],beg[6666],e,safe[1926];
	void add(int u,int v,int wa){
		u<<=1;v<<=1;
		if(wa&&u!=v||!wa&&u==v)++u;
		else ++v;
		to[++e]=v;
		lst[e]=beg[u];
		beg[u]=e;
		w[e]=wa;
	}
	int cur[6666],dis[6666];
	int q[6666],*l,*r;
	int bfs(int s,int t,int n){
		for(int i=0;i<n;++i)cur[i]=beg[i],dis[i]=0x3f3f3f3f;
		dis[s]=0;
		*(l=r=q)=s;
		while(l<=r){
			for(int i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(dis[to[i]],dis[*l]+1))*(++r)=to[i];
			++l;
		}
		return dis[t]!=0x3f3f3f3f;
	}
#define cs cur[s]
	int dfs(int s,int t,int flow){
		
		if(s==t)return flow;
		if(!flow)return 0;
		for(;cs;cs=lst[cs])if(w[cs]&&dis[s]+1==dis[to[cs]]){
			int wr=dfs(to[cs],t,min(flow,w[cs]));
			if(wr){
				w[cs]-=wr;
				w[cs^1]+=wr;
				return wr;
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
		e=1;
		int n=p.size()+1,m=n-1;
		for(int T=0;T<t;++T){
			for(int i=0;i<m;++i){
				add((T*n+i+1),(T+1)*n+p[i],1);
				add((T+1)*n+p[i],T*n+i+1,0);
				add(T*n+p[i],(T+1)*n+i+1,1);
				add((T+1)*n+i+1,T*n+p[i],0);
			}
			for(int i=0;i<n;++i){
				add(T*n+i,(T+1)*n+i,1);
				add((T+1)*n+i,T*n+i,0);
			}
		}
		for(int i=0;i<n;++i)safe[i]=1;
		for(auto i:position)safe[i]=0;
		int u=(t+1)*n;
		for(int i=0;i<u;++i){
			add(i,i,1);
			add(i,i,0);
		}
		for(int i=0;i<n;++i)if(safe[i]){
			add(i+t*n,u,1);
			add(u,i+t*n,0);
		}
		else{
			add(u,i,1);
			add(i,u,0);
		}
		return dinic(u*2+1,u*2,(u+1)*2);
    }
};

// CUT begin
ifstream data("Apocalypse.sample");

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
    Apocalypse *instance = new Apocalypse();
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
        int T = time(NULL) - 1520148292;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 800 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Apocalypse (800 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
