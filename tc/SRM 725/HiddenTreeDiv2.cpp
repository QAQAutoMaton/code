/*
Author: CNYALI_LK
LANG: C++
PROG: HiddenTreeDiv2.cpp
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

class HiddenTreeDiv2 {
    public:
	int want[1926],have[1926],n;
	int dfs(int x){
		if(x>n)return 1;
		if(want[x]>have[x])return 0;
		int tmx=0x3f3f3f3f;
		for(int i=x+1;i<=n;++i){
			if(want[i]>have[i])chkmax(tmx,want[i]-have[i]);	
		}
		if(tmx<want[x])return 0;
		if(dfs(x+1))return 1;
		for(int i=x+1;i<=n;++i)if(have[i]+have[x]<=want[i]){
			have[i]+=have[x];
			if(dfs(x+1))return 1;
			have[i]-=have[x];
		}
		return 0;
	}
    string isPossible(vector<int> a, vector<int> b) {
		n=a.size();
		for(int i=0;i<n;++i)if(a[i]>b[i])return "Impossible";
		for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)if(b[i]>b[j]){swap(b[i],b[j]);swap(a[i],a[j]);}
		for(int i=0;i<n;++i)want[i+1]=b[i],have[i+1]=a[i];
        return dfs(1)?"Possible":"Impossible";
    }
};

// CUT begin
ifstream data("HiddenTreeDiv2.sample");

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

bool do_test(vector<int> a, vector<int> b, string __expected) {
    time_t startClock = clock();
    HiddenTreeDiv2 *instance = new HiddenTreeDiv2();
    string __result = instance->isPossible(a, b);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519780058;
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
        cout << "HiddenTreeDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
