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
#include <tr1/unordered_set>
using namespace std;

class TrisomorphismEasy {
    public:
	int a[15],ft[15];
	tr1::unordered_set<long long> se;
	long long jmcnt[24333333];
	int count(long long tos){
		int fa=tos%19260817;	
		while(~jmcnt[fa]){
			if(jmcnt[fa]==tos)return 1;
			++fa;
		}
		return 0;
	}
	void insert(long long tos){
		int fa=tos%19260817;	
		while(~jmcnt[fa]){
			++fa;
		}
		jmcnt[fa]=tos;
	}
    int count(vector<int> edgeTo) {
		memset(jmcnt,-1,sizeof(jmcnt));
		int n=edgeTo.size();
		for(int i=0;i<n;++i)a[i]=i;
		int t,cnt=-1;
		do{
			t=1;
			for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)t^=a[i]>a[j];
			if(t){
				for(int i=0;i<n;++i)ft[a[i]]=a[edgeTo[i]];
				long long tos=0;
				for(int i=0;i<n;++i){
					tos=tos*n+ft[i];
				}
				if(!count(tos)){
					insert(tos);
					++cnt;
				}
			}
		}while(next_permutation(a,a+n));
        return cnt;
    }
};

// CUT begin
ifstream data("TrisomorphismEasy.sample");

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

bool do_test(vector<int> edgeTo, int __expected) {
    time_t startClock = clock();
    TrisomorphismEasy *instance = new TrisomorphismEasy();
    int __result = instance->count(edgeTo);
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
        vector<int> edgeTo;
        from_stream(edgeTo);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(edgeTo, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519354957;
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
        cout << "TrisomorphismEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
