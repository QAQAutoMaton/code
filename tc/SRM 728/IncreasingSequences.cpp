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
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;
class IncreasingSequences {
    public:
	ll f[333][633],inv[333];
	vector<int> lsh;
	const ll p=998244353;
    int count(vector<int> L, vector<int> R) {
		
		ll n=L.size();
		L.insert(L.begin(),0);
		R.insert(R.begin(),0);
		inv[1]=1;
		for(ll i=2;i<=n;++i){
			inv[i]=(p-p/i)*inv[p%i]%p;
//			if(inv[i]*i%p!=1)printf("fuckyou?%lld %lld\n",i,inv[i]);
		}
		for(ll i=1;i<=n;++i)lsh.push_back(L[i]),lsh.push_back(R[i]+1);
		sort(lsh.begin(),lsh.end());
		lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
		ll m=lsh.size()-1;
		lsh.insert(lsh.begin(),0);
		for(ll i=1;i<=n;++i){
			L[i]=lower_bound(lsh.begin()+1,lsh.end(),L[i])-lsh.begin();
			R[i]=upper_bound(lsh.begin()+1,lsh.end(),R[i])-lsh.begin()-1;
		}
		f[0][0]=1;
		for(ll i=1;i<=m;++i)f[0][i]=1;
		for(ll i=1;i<=n;++i){
			for(ll j=L[i];j<=R[i];++j){
				f[i][j]=f[i][j-1];
				ll s=1;
				for(ll k=i;L[k]<=j&&j<=R[k];--k){
					s=s*(lsh[j+1]-lsh[j]-(i-k))%p*inv[i-k+1]%p;
					f[i][j]=(f[i][j]+s*f[k-1][j-1])%p;
				}
			}
			for(ll j=R[i]+1;j<=m;++j)f[i][j]=f[i][j-1];
		}
        return (int)f[n][m];
    }
};

// CUT begin
ifstream data("IncreasingSequences.sample");

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
    ll len;
    from_stream(len);
    ts.clear();
    for (ll i = 0; i < len; ++i) {
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

bool do_test(vector<ll> L, vector<ll> R, ll __expected) {
    time_t startClock = clock();
    IncreasingSequences *instance = new IncreasingSequences();
    ll __result = instance->count(L, R);
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
        vector<ll> L;
        from_stream(L);
        vector<ll> R;
        from_stream(R);
        next_line();
        ll __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(L, R, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        ll T = time(NULL) - 1519369733;
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
        cout << "IncreasingSequences (500 Polls)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
