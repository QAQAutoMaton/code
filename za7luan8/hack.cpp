#define  REP(i, s, e) for(register int i = s; i <= e ;i++)
#define DREP(i, s, e) for(register int i = s; i >= e ;i--)

#define DEBUG fprintf(stderr, "Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

long long m, n, k;

int main()
{
	cin >> n >> m;
	long long ans = 0, left = m - 1;
	long long res = 1;
	while (n--)
	{
		scanf("%lld", &k);
		if (k == 1)
		{
			if (left) left--, ans++;
			continue;
		}
		res = (res * k) % MOD;
	}
	cout << (ans + res) % MOD;
	return 0;
}
