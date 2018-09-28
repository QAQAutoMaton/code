/*
Author: CNYALI_LK
LANG: C++
PROG: GravityPuzzle.cpp
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

class GravityPuzzle {
    public:
	const int p=1000000007;
	int hang[66],lie[66],fac[66],invf[66],inv[66],c[66][66];
	int hs[66],ls[66];
	int calc(int n,int m){
		int han=fac[n],hanga=1,liea=1;
		for(int i=0;i<n;++i){
			++hs[hang[i]];
			hanga=(long long)hanga*c[m][hang[i]]%p;
		}
		for(int i=0;i<=m;++i)han=(long long)han*invf[hs[i]]%p;

		for(int i=0;i<m;++i){
			++ls[lie[i]];
			liea=(long long)liea*c[n][lie[i]]%p;
		}
		int li=fac[m];
		for(int i=0;i<=n;++i)li=(long long)li*invf[ls[i]]%p;
		int ansa=(long long)hanga*han%p,ansb=(long long)liea*li%p,ansc=(long long)han*li%p;
//		printf("%d %d %d %d\n",han,hanga,li,liea);
		return ((ansa+ansb-ansc)%p+p)%p;
	}
    int count(vector<string> board) {
		int n=board.size(),m=board[0].length();
		for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(board[i][j]=='#')++hang[i],++lie[j];
//		for(int i=0;i<n;++i)cout<<board[i]<<endl;
		int t=50;
		for(int i=0;i<=t;++i){
			c[i][0]=c[i][i]=1;
			for(int j=1;j<i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
		}
		fac[0]=fac[1]=inv[1]=invf[0]=invf[1]=1;
		for(int i=2;i<=t;++i){
			fac[i]=((long long)fac[i-1]*i)%p;
			inv[i]=(long long )(p-p/i)*(long long )inv[p%i]%p;
			invf[i]=(long long)invf[i-1]*inv[i]%p;
		}
		int up=1,down=1,left=1,right=1;
		for(int i=0;i<n;++i){
			int j=0;
			while(j<m&&board[i][j]=='#')++j;
			left&=(j==hang[i]);
			j=m;
			while(j&&board[i][j-1]=='#')--j;
			right&=(m-j==hang[i]);
		}
		for(int j=0;j<m;++j){
			int i=0;
			while(i<n&&board[i][j]=='#')++i;
			up&=(i==lie[j]);
			i=n;
			while(i&&board[i-1][j]=='#')--i;
			down&=(n-i==lie[j]);
		}
		int h=left^right;
		int l=up^down;
		if(h){
			if(l){
				return calc(n,m);
			}
			else{
				int ans=1;
				for(int i=0;i<n;++i){
					ans=(long long)ans*c[m][hang[i]]%p;
				}
				return ans;
			}
		}
		else{
			if(l){
				int ans=1;
				for(int i=0;i<m;++i){
					ans=ans*((long long)c[n][lie[i]])%p;
				}	
				return ans;
			}
			else{
				return 1;	
			}
		}
        return 0;
    }
};

// CUT begin
ifstream data("GravityPuzzle.sample");

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

bool do_test(vector<string> board, int __expected) {
    time_t startClock = clock();
    GravityPuzzle *instance = new GravityPuzzle();
    int __result = instance->count(board);
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
        vector<string> board;
        from_stream(board);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(board, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519825168;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GravityPuzzle (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
