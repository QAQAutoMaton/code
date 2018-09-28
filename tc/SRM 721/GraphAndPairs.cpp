/*
Author: CNYALI_LK
LANG: C++
PROG: GraphAndPairs.cpp
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

class GraphAndPairs {
    public:
	vector<int> two(int k){
		vector<int> edges;
		int s,t=-1,S;
		while(k){
			s=0;
			while((s*(s+1))>>1<=k)++s;
			k-=s*(s-1)>>1;
			S=++t;
			for(int i=1;i<=s;++i,edges.push_back(S))
				edges.push_back(++t);
		}
		edges.insert(edges.begin(),t+1);
		return edges;
	}
    vector<int> construct(int d, int k) {
		if(d==2)return two(k);
		vector<int> edges;
		int s=0,t=-1,S,T;
		while((s+1)*(s+1)<=k)++s;
		S=t+1;
		T=t+d-1;
		t=T;
		for(int i=S;i<T;++i){
			edges.push_back(i);
			edges.push_back(i+1);
		}
		for(int i=1;i<=s;++i){
			edges.push_back(++t);
			edges.push_back(S);
		}
		for(int i=1;i<=s;++i){
			edges.push_back(++t);
			edges.push_back(T);
		}
		k-=s*s;
		if(k){
			s=k;
			S=t+1;
			T=t+d-1;
			t=T;
			for(int i=S;i<T;++i){
				edges.push_back(i);
				edges.push_back(i+1);
			}
			for(int i=1;i<=1;++i){
				edges.push_back(++t);
				edges.push_back(S);
			}
			for(int i=1;i<=s;++i){
				edges.push_back(++t);
				edges.push_back(T);
			}
		}
		edges.insert(edges.begin(),t+1);
        return edges;
    }
};

// CUT begin
ifstream data("GraphAndPairs.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int d, int k, vector<int> __expected) {
    time_t startClock = clock();
    GraphAndPairs *instance = new GraphAndPairs();
    vector<int> __result = instance->construct(d, k);
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
        int d;
        from_stream(d);
        int k;
        from_stream(k);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1520144195;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GraphAndPairs (450 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
