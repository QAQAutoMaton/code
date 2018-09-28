/*
Author: CNYALI_LK
LANG: C++
PROG: SimpleMazeEasy.cpp
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
struct matrix{
	ll a[3][3];
	ll *operator[](ll b){return a[b];}
	matrix operator +(matrix b){
		matrix c;
		for(ll i=0;i<3;++i)for(ll j=0;j<3;++j)c[i][j]=(a[i][j]+b[i][j])%p;
		return c;
	}
	matrix operator *(matrix b){
		matrix c;
		for(ll i=0;i<3;++i)for(ll j=0;j<3;++j){
			c[i][j]=0;
			for(ll k=0;k<3;++k)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%p;
		}
		return c;	
	}
	matrix operator ^(ll b){
		matrix a=*this,c;
		for(ll i=0;i<3;++i)for(ll j=0;j<3;++j)c[i][j]=i==j;
		while(b){
			if(b&1)c=c*a;
			a=a*a;
		}
		return c;
	}
};
matrix a,b,c;
void qsum(long long n){
	if(n==1){
		for(ll i=0;i<3;++i)for(ll j=0;j<3;++j)c[i][j]=(i==j);
		b=a;
		return ;
	}
	if(n&1){
		qsum(n-1);
		c=c+b;
		b=b*a;
	}
	else{
		qsum(n>>1);
		c=c+c*b;
		b=b*b;
	}
}
class SimpleMazeEasy {
    public:
    ll findSum(long long n) {
		if(n==1){
			return 16;
		}
		for(ll i=0;i<3;++i)for(ll j=0;j<3;++j)a[i][j]=(i<=j);
		qsum(n-1);
		for(ll i=0;i<3;++i)for(ll j=0;j<3;++j)b[i][j]=!j;

		a=c*b;
		n%=p;
		ll s1=a[0][0],s2=n;
//		printf("%lld\n",s1);
		s2=(long long)s2*s2%p;
		s1=s1*s2%p;
		s2=(long long)s2*s2%p;
		s2=s2*n%p;
//		printf("%lld %lld\n",s1,s2);
        return (long long)(s1*22+s2*16)%p;
    }
};

// CUT begin
ifstream data("SimpleMazeEasy.sample");

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

bool do_test(long long n, ll __expected) {
    time_t startClock = clock();
    SimpleMazeEasy *instance = new SimpleMazeEasy();
    ll __result = instance->findSum(n);
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
        long long n;
        from_stream(n);
        next_line();
        ll __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        ll T = time(NULL) - 1519884427;
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
        cout << "SimpleMazeEasy (1000 Polls)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
