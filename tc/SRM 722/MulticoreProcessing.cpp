/*
Author: CNYALI_LK
LANG: C++
PROG: MulticoreProcessing.cpp
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

class MulticoreProcessing {
    public:
    long long fastestTime(long long jobLength, int corePenalty, vector<int> speed, vector<int> cores) {
		long long mintime=0x3f3f3f3f3f3f3f3f,att,n=speed.size(),speedd,coress;
		for(int i=0;i<n;++i){
			speedd=speed[i];coress=cores[i];	
			double faq=jobLength*1./speedd;
			long long l=1,r=coress-1,mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(faq/mid>=faq/(mid+1)+corePenalty)l=mid+1;
				else r=mid-1;
			}
			att=(l-1)*corePenalty;
			att+=jobLength/speedd/l;
			if(jobLength%(speedd*l))++att;
			chkmin(mintime,att);
		}
        return mintime;
    }
};

// CUT begin
ifstream data("MulticoreProcessing.sample");

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

bool do_test(long long jobLength, int corePenalty, vector<int> speed, vector<int> cores, long long __expected) {
    time_t startClock = clock();
    MulticoreProcessing *instance = new MulticoreProcessing();
    long long __result = instance->fastestTime(jobLength, corePenalty, speed, cores);
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
        long long jobLength;
        from_stream(jobLength);
        int corePenalty;
        from_stream(corePenalty);
        vector<int> speed;
        from_stream(speed);
        vector<int> cores;
        from_stream(cores);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(jobLength, corePenalty, speed, cores, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519953095;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 350 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "MulticoreProcessing (350 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
