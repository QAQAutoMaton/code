/*
Author: CNYALI_LK
LANG: C++
PROG: TileFlippingGame.cpp
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

class TileFlippingGame {
    public:
	int is[24][24],col[24][24],ans[456][2],tans[2],csm,t[24][24],sum[456];
	void dfs(int x,int y){
		if(!(~is[x][y])||col[x][y])return;
		col[x][y]=csm;
		++sum[csm];
		dfs(x-1,y);
		dfs(x+1,y);
		dfs(x,y-1);
		dfs(x,y+1);
	}
	int dfs2(int x,int y,int c){
		if(c!=t[x][y])return 0;
		int ans=1;
		t[x][y]^=1;
		ans+=dfs2(x-1,y,c);
		ans+=dfs2(x+1,y,c);
		ans+=dfs2(x,y-1,c);
		ans+=dfs2(x,y+1,c);
		return ans;
	}
    int HowManyMoves(int n, int m, vector<string> X) {
		for(int i=0;i<=n;++i)is[i][0]=is[i][m+1]=-1;
		for(int i=0;i<=m;++i)is[0][i]=is[n+1][i]=-1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				is[i][j]=X[i-1][j-1]=='w'?1:X[i-1][j-1]=='b'?0:-1;
			}
		}	
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if((~is[i][j])&&!col[i][j]){
			++csm;dfs(i,j);
			ans[csm][0]=ans[csm][1]=0x3f3f3f3f;
		}

		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(~is[i][j]){
			for(int k=0;k<=n+1;++k)for(int l=0;l<=m+1;++l)t[k][l]=is[k][l];
			int to=0;
			while(dfs2(i,j,t[i][j])!=sum[col[i][j]])++to;
			chkmin(ans[col[i][j]][t[i][j]^1],to);
			chkmin(ans[col[i][j]][t[i][j]],to+1);
		}
		for(int i=1;i<=csm;++i)tans[0]+=ans[i][0],tans[1]+=ans[i][1];
        return min(tans[0],tans[1]);
    }
};

// CUT begin
ifstream data("TileFlippingGame.sample");

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

bool do_test(int n, int m, vector<string> X, int __expected) {
    time_t startClock = clock();
    TileFlippingGame *instance = new TileFlippingGame();
    int __result = instance->HowManyMoves(n, m, X);
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
        int n;
        from_stream(n);
        int m;
        from_stream(m);
        vector<string> X;
        from_stream(X);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, m, X, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1522371603;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TileFlippingGame (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
