/*
Author: CNYALI_LK
LANG: C++
PROG: BuffaloBuffaloBuffalo.cpp
Mail: cnyalilk@vip.qq.com
*/

#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<class Ta,class Tb>ll chkmin(Ta &a,Tb b){return a>b?a=b,1:0;}
template<class Ta,class Tb>ll chkmax(Ta &a,Tb b){return a<b?a=b,1:0;}

class BuffaloBuffaloBuffalo {
    public:
	string s;
	const ll p=1000000007;
	ll n;
	tr1::unordered_map<ll,ll> dp[128];
	ll fcount(ll pos,ll a,ll b,ll c,ll d,ll e,ll f){
		if(pos==n)return !(a||b||c||d||e||f);
		ll st=((((a*14+b)*14+c)*14+d)*14+e)*14+f;
		if(dp[pos].count(st))return dp[pos][st];
		if(s[pos]^'?'){
			if(s[pos]!='b'&&s[pos]!='u'&&s[pos]!='f'&&s[pos]!='a'&&s[pos]!='l'&&s[pos]!='o')return dp[pos][st]=0;
			if(s[pos]=='b')return dp[pos][st]=fcount(pos+1,a+1,b,c,d,e,f);
			if(s[pos]=='u')return dp[pos][st]=(a?fcount(pos+1,a-1,b+1,c,d,e,f):0);
			if(s[pos]=='f'){
				ll ans=0;
				if(c)ans=fcount(pos+1,a,b,c-1,d+1,e,f);
				else if(b)ans=fcount(pos+1,a,b-1,c+1,d,e,f);
				return dp[pos][st]=ans;
			}
			if(s[pos]=='a')return dp[pos][st]=(d?fcount(pos+1,a,b,c,d-1,e+1,f):0);
			if(s[pos]=='l')return dp[pos][st]=(e?fcount(pos+1,a,b,c,d,e-1,f+1):0);
			return dp[pos][st]=(f?fcount(pos+1,a,b,c,d,e,f-1):0);
		}
		else{
			ll ans=0;
			ans=ans+fcount(pos+1,a+1,b,c,d,e,f);
			if(a){
				ans=ans+fcount(pos+1,a-1,b+1,c,d,e,f);
			}
			if(c){
				ans=ans+fcount(pos+1,a,b,c-1,d+1,e,f);
			}
			else if(b){
				ans=ans+fcount(pos+1,a,b-1,c+1,d,e,f);
			}
			if(d){
				ans=ans+fcount(pos+1,a,b,c,d-1,e+1,f);
			}
			if(e){
				ans=ans+fcount(pos+1,a,b,c,d,e-1,f+1);
			}
			if(f){
				ans=ans+fcount(pos+1,a,b,c,d,e,f-1);
			}
			ans%=p;
			return dp[pos][st]=ans;
		}
	}
    ll count(string pattern) {
		s=pattern;
		n=s.length();
		if(n%7)return 0;
        return fcount(0,0,0,0,0,0,0);
    }
};

// CUT begin
ifstream data("BuffaloBuffaloBuffalo.sample");

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

bool do_test(string pattern, ll __expected) {
    time_t startClock = clock();
    BuffaloBuffaloBuffalo *instance = new BuffaloBuffaloBuffalo();
    ll __result = instance->count(pattern);
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
        string pattern;
        from_stream(pattern);
        next_line();
        ll __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pattern, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        ll T = time(NULL) - 1519904642;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " polls" << endl;
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
        cout << "BuffaloBuffaloBuffalo (500 Polls)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
