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
template<class Ta,class Tb>int chkmax(Ta &a,Tb b){return a<b?a=b,1:0;}
template<class Ta,class Tb>int chkmin(Ta &a,Tb b){return a>b?a=b,1:0;}
class HeroVacation {
    public:
	int vis[1926],n;
	int dis[66][66];
	int find(int x){
		int sa=0,t=x;
		for(int i=0;i<n;++i){
			if(!vis[i]&&chkmax(sa,dis[x][i]))t=i;
		}
		return t;
	}
    vector<int> getPermutation(vector<int> p) {
		n=p.size()+1;
		memset(dis,0x3f,sizeof(dis));
		for(int i=0;i<n;++i)dis[i][i]=0;
		for(int i=1;i<n;++i){
			dis[i][p[i-1]]=dis[p[i-1]][i]=1;
		}
		for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)chkmin(dis[i][j],dis[i][k]+dis[k][j]);
		int ans=0,ths,now,nxt;
		vector<int> ans_w,ths_w;
		for(int i=0;i<n;++i){
			ths=0;
			ths_w.erase(ths_w.begin(),ths_w.end());
			ths_w.push_back(i);
			memset(vis,0,sizeof(vis));
			
			vis[now=i]=1;
			while((nxt=find(now))!=now){
				ths+=dis[now][nxt];
				ths_w.push_back(nxt);
				vis[now=nxt]=1;
			
			}
			if(chkmax(ans,ths))ans_w=ths_w;
		}
        return ans_w;
    }
};

// CUT begin
ifstream data("HeroVacation.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> p, vector<int> __expected) {
    time_t startClock = clock();
    HeroVacation *instance = new HeroVacation();
    vector<int> __result = instance->getPermutation(p);
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
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519645893;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "HeroVacation (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
