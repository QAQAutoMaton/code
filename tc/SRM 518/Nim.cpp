/*
Author: CNYALI_LK
LANG: C++
PROG: Nim.cpp
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
const ll p=1000000007;
const ll Two=500000004;
class Nim {
    public:
	ll a[1048576],pri[1048576],ps;
	void init_prime(ll n){
		for(ll i=2;i<=n;++i)a[i]=1;
		for(ll i=2;i<=n;++i){
			if(a[i]){
				pri[++ps]=i;
			}
			for(ll j=1;j<=ps&&i*pri[j]<=n;++j){
				a[i*pri[j]]=0;
				if(!(i%pri[j]))break;
			}
		}
	}
	ll fpm(ll a,ll b){
		ll c=1;
		while(b){
			if(b&1)c=c*a%p;
			a=a*a%p;
			b>>=1;	
		}
		return c;
	}
	void fwt(ll n){
		ll u,v;
		for(ll t=1;t<n;t<<=1){
			for(ll l=0;l<n;l+=t+t){
				for(ll i=0;i<t;++i){
					u=a[l+i];
					v=a[l+i+t];
					a[l+i]=(u+v)%p;
					a[l+i+t]=(u-v+p)%p;
				}
			}
		}
	}

	void ifwt(ll n){
		ll u,v;
		for(ll t=1;t<n;t<<=1){
			for(ll l=0;l<n;l+=t+t){
				for(ll i=0;i<t;++i){
					u=a[l+i];
					v=a[l+i+t];
					a[l+i]=(u+v)*Two%p;
					a[l+i+t]=(u-v+p)*Two%p;
				}
			}
		}
	}
    ll count(ll K, ll L) {
		ll n=1;
		while(n<=L)n<<=1;
		init_prime(L);
		fwt(n);
		for(ll i=0;i<n;++i)a[i]=fpm(a[i],K);
		ifwt(n);
        return a[0];
    }
};

// CUT begin
ifstream data("Nim.sample");

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

bool do_test(ll K, ll L, ll __expected) {
    time_t startClock = clock();
    Nim *instance = new Nim();
    ll __result = instance->count(K, L);
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
        ll K;
        from_stream(K);
        ll L;
        from_stream(L);
        next_line();
        ll __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(K, L, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        ll T = time(NULL) - 1522722727;
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
        cout << "Nim (1000 Polls)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
