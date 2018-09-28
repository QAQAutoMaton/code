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
int chkmax(int &a,int b){return a<b?a=b,1:0;}
vector<int> w,son[1024];
int wu[1024];
int cmp(int u,int v){
	return w[u]+wu[v]<w[v]+wu[u];
}
class StonesOnATree {
	private:
#define all(a) a.begin(),a.end()
		int mins(int r){
			for(vector<int> ::iterator i=son[r].begin();i!=son[r].end();++i){
				wu[*i]=mins(*i);
			}
			sort(all(son[r]),cmp);
			int cnt=0,ans=0;
			for(vector<int> ::iterator i=son[r].begin();i!=son[r].end();++i){
				chkmax(ans,wu[*i]+cnt);	
				cnt+=w[*i];
			}
			chkmax(ans,w[r]+cnt);
//			printf("%d is %d\n",r,ans);
			return ans;
		}
    public:
    int minStones(vector<int> p, vector<int> W) {
		int n=p.size();
		for(int i=0;i<=n;++i)son[i].erase(all(son[i]));
		for(int i=1;i<=n;++i)son[p[i-1]].push_back(i);
		w=W;
        return mins(0);
    }
};

// CUT begin
ifstream data("StonesOnATree.sample");

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

bool do_test(vector<int> p, vector<int> w, int __expected) {
    time_t startClock = clock();
    StonesOnATree *instance = new StonesOnATree();
    int __result = instance->minStones(p, w);
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
        vector<int> w;
        from_stream(w);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, w, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519204874;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "StonesOnATree (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
