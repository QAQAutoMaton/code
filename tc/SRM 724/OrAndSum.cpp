/*
Author: CNYALI_LK
LANG: C++
PROG: OrAndSum.cpp
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

class OrAndSum {
    public:
	int rO[66],dnA[66],mst[2][66],a[66];
	int nok(int n,int s){
		a[0]=s;
		for(int i=0;i<n;++i){
			if(dnA[i])if(!a[i])return 1;
			else a[i+1]=1;
			else if(!rO[i])if(a[i])return 1;
			else a[i+1]=0;
			else a[i+1]=a[i]^1;
		}
		return 0;
	}
    string isPossible(vector<long long> ro, vector<long long> mus) {
		int n=ro.size();
		vector<long long> dna;
		for(int i=0;i<n;++i){
			if(mus[i]<ro[i])return "Impossible";
			dna.push_back(mus[i]-ro[i]);
		}
		for(int j=0;j<63;++j){
			for(int i=0;i<=n;++i)mst[0][i]=mst[1][i]=0;
			for(int i=0;i<n;++i){
				if(!(rO[i]=ro[i]&(1LL<<j)?1:0))mst[0][i]=mst[0][i+1]=1;
				if((dnA[i]=dna[i]&(1LL<<j)?1:0))mst[1][i]=mst[1][i+1]=1;	
				
			}
			for(int i=0;i<=n;++i)if(mst[0][i]&&mst[1][i])return "Impossible";
//			for(int i=0;i<n;++i)printf("(%d%d)",rO[i],dnA[i]);
			if(nok(n,0)&&nok(n,1))return "Impossible";
		}
        return "Possible";
    }
};

// CUT begin
ifstream data("OrAndSum.sample");

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

bool do_test(vector<long long> pairOr, vector<long long> pairSum, string __expected) {
    time_t startClock = clock();
    OrAndSum *instance = new OrAndSum();
    string __result = instance->isPossible(pairOr, pairSum);
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
        vector<long long> pairOr;
        from_stream(pairOr);
        vector<long long> pairSum;
        from_stream(pairSum);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pairOr, pairSum, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519819669;
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
        cout << "OrAndSum (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
