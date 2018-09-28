/*
Author: CNYALI_LK
LANG: C++
PROG: DominoTiling.cpp
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

class DominoTiling {
    public:
	long long f[15][1<<12],a[15],n,m,t,fa_q;
	int check(int x){
		while(x){
			int t=x&(-x);
			x^=t;
			t<<=1;
			if(!(x&t))return 0;
			x^=t;
		}
		return 1;
	}
	void Ex(int x,int y){
		int fa=fa_q^y;
		for(int i=fa;i;i=(i-1)&fa)if(check(i)){
			int j=y|i;
			if(!((j^fa_q)&a[x+1]))f[x+1][(j^fa_q)|a[x+1]]+=f[x][y];
		}
	}
    long long count(vector<string> grid) {
		n=grid.size(),m=grid[0].length(),t=1<<m,fa_q=t-1;

		for(int i=0;i<n;++i){
			a[i]=0;
			for(int j=0;j<m;++j)if(grid[i][j]=='X'){
				a[i]|=1<<j;
			}
			//printf("%d%c",a[i],i==n-1?'\n':' ');
		}	
		f[0][a[0]]=1;
		for(int i=0;i<n;++i)for(int j=0;j<t;++j)if((~j)&a[i])f[i][j]=0;
		else if(f[i][j]){
			Ex(i,j);
			if(!((j^fa_q)&a[i+1]))f[i+1][(j^fa_q)|a[i+1]]+=f[i][j];
		}
		long long ans=0;
//		for(int i=0;i<n;++i)for(int j=0;j<t;++j)printf("%d%c",f[i][j],j==t-1?'\n':' ');
		for(int i=0;i<t;++i){
//			printf("%d,%d,%d,%d\n",f[n-1][i],i&a[n-1],a[n-1],check(i^fa_q));
			if(((i&a[n-1])==a[n-1])&&check(i^fa_q))ans+=f[n-1][i];
		}
		return ans;
    }
};

// CUT begin
ifstream data("DominoTiling.sample");

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

bool do_test(vector<string> grid, long long __expected) {
    time_t startClock = clock();
    DominoTiling *instance = new DominoTiling();
    long long __result = instance->count(grid);
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
        vector<string> grid;
        from_stream(grid);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(grid, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519954555;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "DominoTiling (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
