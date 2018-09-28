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

template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
class ManageSubsequences {
    public:
	int aft[303][303][303],bef[303][303][303];
    int minAdded(string S, string A, string B) {
		memset(bef,0x3f,sizeof(bef));
		memset(aft,0x3f,sizeof(aft));
		bef[0][0][0]=0;
		int ls=S.length(),la=A.length(),lb=B.length();
		S=S+'#';
		A=A+' ';
		B=B+' ';

		for(int i=0;i<=ls;++i){
			for(int j=0;j<=la;++j)for(int k=0;k<lb;++k){
				chkmin(aft[i][j+(A[j]==S[i])][k+(B[k]==S[i])],bef[i][j][k]);	
				chkmin(bef[i][j+1][k+(A[j]==B[k])],bef[i][j][k]+1);
				chkmin(bef[i+1][j][k],aft[i][j][k]);
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<lb;++i)chkmin(ans,bef[ls][la][i]);

        return ans==0x3f3f3f3f?-1:ans;
    }
};

// CUT begin
ifstream data("ManageSubsequences.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string S, string A, string B, int __expected) {
    time_t startClock = clock();
    ManageSubsequences *instance = new ManageSubsequences();
    int __result = instance->minAdded(S, A, B);
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
        string S;
        from_stream(S);
        string A;
        from_stream(A);
        string B;
        from_stream(B);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, A, B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519446674;
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
        cout << "ManageSubsequences (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
