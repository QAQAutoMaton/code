/*
Author: CNYALI_LK
LANG: C++
PROG: RememberWords.cpp
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

class RememberWords {
    public:
/*
if w<d1:
	w(w+1)/2<=w1<=wd1+d1(d1-1)/2
else:
	wd1-d1(d1-1)/2<=w1<=wd1+d1(d1-1)/2


if w<=d2:
	w(w-1)/2<=w2<=wd2+d2(d2+1)/2
else:
	wd2-d2(d2+1)/2<=w2<=wd2+d2(d2+1)/2
*/
#define x first
#define y second
	ll ef(ll w){
		ll l=1,r=w,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*(mid+1)>>1<=w)l=mid+1;
			else r=mid-1;
		}
		return l-1;
	}
	ll getup(ll w,ll x,ll y){
		w+=(x*y)/2;
		w/=x;
		return w;
	}
	ll getdown(ll w,ll x,ll y){
		w-=(x*y)/2;
		w=(w/x)+bool(w%x);
		return w;
	}
	pii hb(pii a,pii b){
		return pii(max(a.x,b.x),min(a.y,b.y));
	}
    string isPossible(ll d1, ll d2, ll w1, ll w2) {
		ll aup1=ef(w1),bup1=ef(w2)+1,aup2=getup(w1,d1,d1-1),bup2=getup(w2,d2,d2+1),adown=getdown(w1,d1,d1-1),bdown=getdown(w2,d2,d2+1);
		chkmax(adown,0);
		chkmax(bdown,0);
		pair<ll,ll> a1(adown,aup1),a2(adown,aup2),b1(bdown,bup1),b2(bdown,bup2),sa(0,d1-1),sb(0,d2),ta(d1,1000000007),tb(d2+1,1000000007);
		pii hb1,hb2,hb3,hb4;
		hb1=hb(hb(a1,b1),hb(sa,sb));
		hb2=hb(hb(a1,b2),hb(sa,tb));
		hb3=hb(hb(a2,b1),hb(ta,sb));
		hb4=hb(hb(a2,b2),hb(ta,tb));
		if(hb1.x<=hb1.y||hb2.x<=hb2.y||hb3.x<=hb3.y||hb4.x<=hb4.y)return "Possible";
		else return "Impossible";
        return "";
    }
};

// CUT begin
ifstream data("RememberWords.sample");

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

bool do_test(ll d1, ll d2, ll w1, ll w2, string __expected) {
    time_t startClock = clock();
    RememberWords *instance = new RememberWords();
    string __result = instance->isPossible(d1, d2, w1, w2);
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
        ll d1;
        from_stream(d1);
        ll d2;
        from_stream(d2);
        ll w1;
        from_stream(w1);
        ll w2;
        from_stream(w2);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d1, d2, w1, w2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        ll T = time(NULL) - 1520082215;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " polls" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
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
        cout << "RememberWords (250 Polls)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
