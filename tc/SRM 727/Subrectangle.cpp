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

class Subrectangle {
    public:
    int minMissed(string S) {
		int n=S.length(),lx=n,rx=-1,cnt=0;
		for(int i=0;i<n;++i)if(S[i]=='#'){
			if(lx==n)lx=i;
			rx=i;
			++cnt;
		}
		if(lx==n)return 1;
		if(rx-lx+1==cnt)return 0;
		int minx=0x3f3f3f3f,t=0,py=0,z0,z1;
		for(int K=2;K<=n;++K)for(int k=1;k<K;++k){
			py=lx;
			t=0;
			if(lx/K!=(lx+k-1)/K){
				py+=(t+=(K-lx%K));
			}
			z0=0;z1=k;
			for(int i=lx;i<=rx;++i){
				if(z1){
					if(S[i]=='#'){--z1;++py;}
					else{
						py+=z1;
						t+=z1;
						z1=0;
						--i;
					}
					if(!z1)z0=K-k;
				}
				else{
					if(S[i]=='.'){--z0;++py;}
					else{
						py+=z0;
						t+=z0;
						z0=0;
						--i;
					}
					if(!z0)z1=k;
				}
			}
			if(z1){
				t+=z1;
				py+=z1;
			}
			py+=n-rx-1;
			if(py%K)t+=K-(py%K);
			minx=min(minx,t);
		}
		
        return minx;
    }
};

// CUT begin
ifstream data("Subrectangle.sample");

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

bool do_test(string S, int __expected) {
    time_t startClock = clock();
    Subrectangle *instance = new Subrectangle();
    int __result = instance->minMissed(S);
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
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519461625;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Subrectangle (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
