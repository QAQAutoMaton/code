/*
Author: CNYALI_LK
LANG: C++
PROG: ExpectedMinimumPower.cpp
Mail: cnyalilk@vip.qq.com
*/

#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<class Ta,class Tb>ll chkmin(Ta &a,Tb b){return a>b?a=b,1:0;}
template<class Ta,class Tb>ll chkmax(Ta &a,Tb b){return a<b?a=b,1:0;}

class ExpectedMinimumPower {
    public:
	const ll p=1e9+7;
	ll fpm(ll a,ll b){
		ll c=1;
		while(b){
			if(b&1)c=c*a%p;
			a=a*a%p;
			b>>=1;
		}
		return c;
	}
    ll findExp(ll n, ll x) {
		ll ans=fpm(2,n),t=1;
		ans=(ans+p-t)%p;
		for(ll i=1;i<x;++i){
			t=t*(n-i+1)%p*fpm(i,p-2)%p;
			ans=(ans+p-t)%p;
		}
        return ans*2%p;
    }
};

// CUT begin
ifstream data("ExpectedMinimumPower.sample");

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

bool do_test(ll n, ll x, ll __expected) {
    time_t startClock = clock();
    ExpectedMinimumPower *instance = new ExpectedMinimumPower();
    ll __result = instance->findExp(n, x);
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

ll run_test(bool mainProcess, const set<ll> &case_set, const string command) {
    ll cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        ll n;
        from_stream(n);
        ll x;
        from_stream(x);
        next_line();
        ll __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, x, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        ll T = time(NULL) - 1521796343;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " polls" << endl;
    }
    return 0;
}

int main(ll argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<ll> cases;
    bool mainProcess = true;
    for (ll i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ExpectedMinimumPower (1000 Polls)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
