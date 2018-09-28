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
void chkmax(int &a,int b){a=a<b?b:a;}
vector<int> son[1024],w;	
int ct[1024];
int cmp(int a,int b){
	return ct[a]>ct[b]; 
}

class StonesOnATreeDiv2 {
    public:
	int mins(int r){
//		printf("vis %d\n",r);
		int ans=0,cnt=0,sz=son[r].size();
		sort(son[r].begin(),son[r].end(),cmp);
		for(int i=0;i<sz;++i){
//			printf("%d,%d!\n",r,son[r][i]);
			chkmax(ans,cnt+mins(son[r][i]));
			cnt+=w[son[r][i]];
		}
		chkmax(ans,cnt+w[r]);
//		printf("%d ans is %d\n",r,ans);
		return ans;
	}
    int minStones(vector<int> p, vector<int> wa) {
		int n=p.size();
		for(int i=0;i<n;++i)son[p[i]].push_back(i+1);
		for(int i=0;i<=n;++i)ct[i]=i;
		for(int i=n;i;--i)ct[p[i-1]]=max(ct[p[i-1]],ct[i]);
//		for(int i=0;i<=n;++i)printf("%d%c",ct[i],i==n?'\n':' ');
		w=wa;
        return mins(0);
    }
};

// CUT begin
ifstream data("StonesOnATreeDiv2.sample");

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
    StonesOnATreeDiv2 *instance = new StonesOnATreeDiv2();
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
        int T = time(NULL) - 1519129129;
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
        cout << "StonesOnATreeDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
