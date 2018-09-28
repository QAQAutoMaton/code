/*
Author: CNYALI_LK
LANG: C++
PROG: SquadConstructor2.cpp
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
#define bitc __builtin_popcountll
const int M=43046721;
class SquadConstructor2 {
    public:
	bitset<M> f[9];

    int teamget(int n, int k, vector<int> friends) {
		f[0][0]=1;
		
		sort(all(friends),[](int a,int b){return bitc(a)<bitc(b);});
		for(auto i=friends.begin();i!=friends.end();++i){
			int cnt=0;
			for(auto j=i+1;j!=friends.end();++j)cnt+=(((*i)&(*j))==(*i));
			if(cnt>=k){
				swap(*i,friends.back());
				friends.pop_back();
			}
		}
		for(auto s:friends){
			int x=0;
			for(int i=0;i<n;++i,s>>=1)x=x*9+(s&1);
			for(int i=k;i;--i)f[i]|=f[i-1]<<x;
		}
		int ans=0,t,p;
		for(int i=0;i<M;++i)if(f[k][i]){
			t=0;
			p=i;
			while(p){
				t+=(p%9)*(p%9);
				p/=9;
			}
			chkmax(ans,t);	
		}
        return ans;
    }
};

// CUT begin
ifstream data("SquadConstructor2.sample");

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

bool do_test(int n, int k, vector<int> friends, int __expected) {
    time_t startClock = clock();
    SquadConstructor2 *instance = new SquadConstructor2();
    int __result = instance->teamget(n, k, friends);
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
        int k;
        from_stream(k);
        vector<int> friends;
        from_stream(friends);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, k, friends, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1521796098;
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
        cout << "SquadConstructor2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
