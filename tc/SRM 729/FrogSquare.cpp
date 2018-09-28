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

class FrogSquare {
    public:
#define sqr(x) ((x)*(x))
	int dx[8888],dy[8888],t;
	int dis[8888],q[8888],*l,*r;
    int minimalJumps(int n, int d, int sx, int sy, int tx, int ty) {
		t=0;
		d*=d;
		dx[++t]=sx;
		dy[t]=sy;
		dx[++t]=tx;
		dy[t]=ty;
		if(sx==tx&&sy==ty)return 0;
		for(int i=0;i<n;++i){
			dx[++t]=i;
			dy[t]=0;
			dx[++t]=i;
			dy[t]=n-1;
			dx[++t]=0;
			dy[t]=i;
			dx[++t]=n-1;
			dy[t]=i;
		}
		*(l=r=q)=1;
		memset(dis,0x3f,sizeof(dis));
		dis[1]=0;
		while(l<=r){
			for(int i=1;i<=t;++i)if(dis[i]==0x3f3f3f3f&&sqr(dx[i]-dx[*l])+sqr(dy[i]-dy[*l])>=d){
				dis[*(++r)=i]=dis[*l]+1;
			}
			++l;
		}
        return dis[2]==0x3f3f3f3f?-1:dis[2];
    }
};

// CUT begin
ifstream data("FrogSquare.sample");

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

bool do_test(int n, int d, int sx, int sy, int tx, int ty, int __expected) {
    time_t startClock = clock();
    FrogSquare *instance = new FrogSquare();
    int __result = instance->minimalJumps(n, d, sx, sy, tx, ty);
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
        int n;
        from_stream(n);
        int d;
        from_stream(d);
        int sx;
        from_stream(sx);
        int sy;
        from_stream(sy);
        int tx;
        from_stream(tx);
        int ty;
        from_stream(ty);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, d, sx, sy, tx, ty, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519301677;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "FrogSquare (450 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
