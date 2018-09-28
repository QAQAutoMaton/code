/*
Author: CNYALI_LK
LANG: C++
PROG: TheRoundCityDiv1.cpp
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

class TheRoundCityDiv1 {
    public:
	ll p[1024242],pri[1024242],ps,phi[1024242],mu[1024242];
	vector<ll> factors[1024242];
	void init_phi(ll n){
		phi[1]=1;	
		mu[1]=1;
		factors[1].push_back(1);
		for(ll i=2;i<=n;++i){
			factors[i].push_back(1);
			if(!p[i]){
				pri[++ps]=i;
				phi[i]=i-1;
				mu[i]=-1;
			}
			for(ll j=1;j<=ps&&i*pri[j]<=n;++j){
				p[i*pri[j]]=1;
				if(i%pri[j]){
					phi[i*pri[j]]=phi[i]*(pri[j]-1);
					mu[i*pri[j]]=-mu[i];
				}
				else {
					phi[i*pri[j]]=phi[i]*pri[j];
					mu[i*pri[j]]=0;
					break;
				}
			}
			for(ll j=i;j<=n;j+=i)factors[j].push_back(i);
		}
	}
	ll ff(ll a,ll b){
		if(!b)return 0;
		ll ans=0;
		for(auto i:factors[b]){
			ans+=mu[i]*(a/i);		
		}
		return ans;
	}
    long long find(ll r) {
		init_phi(r);
		ll ans=1;
		ll s=r;
		for(ll i=1;i<r;++i){
			while(s*s+i*i>r*r)--s;
			ans+=ff(s,i);
		}
        return ans*4;
    }
};

// CUT begin
ifstream data("TheRoundCityDiv1.sample");

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

bool do_test(ll r, long long __expected) {
    time_t startClock = clock();
    TheRoundCityDiv1 *instance = new TheRoundCityDiv1();
    long long __result = instance->find(r);
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
        ll r;
        from_stream(r);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(r, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        ll T = time(NULL) - 1530867858;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " polls" << endl;
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
        cout << "TheRoundCityDiv1 (300 Polls)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
