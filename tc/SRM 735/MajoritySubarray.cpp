/*
Author: CNYALI_LK
LANG: C++
PROG: MajoritySubarray.cpp
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

class MajoritySubarray {
	public:
		ll a[102424],b[102424],c[202424],N;
		ll mo;
		void Add(ll x,ll y){
			while(x<=N){
				c[x]+=y;
				x+=x&(-x);
			}
		}
		ll Sum(ll x){
			ll s=0;
			while(x){
				s+=c[x];
				x^=x&(-x);
			}
			return s;
		}
	

		long long getCount(ll n, ll seed, ll m) {
			N=n*2+3;
			mo=(1LL<<31)-1;
			for(ll i=1;i<=n;++i){
				a[i]=(seed>>16)%m;
				seed=(seed*1103515245+12345)&mo;
			}
			b[0]=n+1;
			ll ans=0;

			for(ll cl=0;cl<m;++cl){
				for(ll i=0;i<=N;++i)c[i]=0;
				Add(b[0],1);
				for(ll i=1;i<=n;++i){
					b[i]=b[i-1]+(a[i]==cl?1:-1);
					Add(b[i],1);
					ans+=Sum(b[i]-1);
				}
			}
			return ans;
		}
};

// CUT begin
ifstream data("MajoritySubarray.sample");

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

bool do_test(ll n, ll seed, ll m, long long __expected) {
	time_t startClock = clock();
	MajoritySubarray *instance = new MajoritySubarray();
	long long __result = instance->getCount(n, seed, m);
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
		ll seed;
		from_stream(seed);
		ll m;
		from_stream(m);
		next_line();
		long long __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if ( do_test(n, seed, m, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		ll T = time(NULL) - 1530795592;
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
		cout << "MajoritySubarray (1000 Polls)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
