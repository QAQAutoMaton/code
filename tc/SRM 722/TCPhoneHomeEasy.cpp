/*
Author: CNYALI_LK
LANG: C++
PROG: TCPhoneHomeEasy.cpp
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

class TCPhoneHomeEasy {
    public:
	int to[1926081][10],oki[1926081],t=1,pows[10];
	int getcnt(int r,int dig){
		if(oki[r])return pows[dig];
		int ans=0;
		for(int i=0;i<10;++i)if(to[r][i])ans+=getcnt(to[r][i],dig-1);
		return ans;
	}
    int validNumbers(int digits, vector<string> specialPrefixes) {
		pows[0]=1;
		for(int i=1;i<=digits;++i)pows[i]=pows[i-1]*10;
		for(auto s:specialPrefixes){
			int r=1;
			for(int i=0;i<s.length();r=to[r][s[i]-'0'],++i)if(!to[r][s[i]-'0'])to[r][s[i]-'0']=++t;
			oki[r]=1;
		}
        return pows[digits]-getcnt(1,digits);
    }
};

// CUT begin
ifstream data("TCPhoneHomeEasy.sample");

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

bool do_test(int digits, vector<string> specialPrefixes, int __expected) {
    time_t startClock = clock();
    TCPhoneHomeEasy *instance = new TCPhoneHomeEasy();
    int __result = instance->validNumbers(digits, specialPrefixes);
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
        int digits;
        from_stream(digits);
        vector<string> specialPrefixes;
        from_stream(specialPrefixes);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(digits, specialPrefixes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519912453;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 400 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TCPhoneHomeEasy (400 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
