#define  REP(i, s, e) for(register int i = s; i <= e ;i++)
#define DREP(i, s, e) for(register int i = s; i >= e ;i--)

#define DEBUG fprintf(stderr, "Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#include <bits/stdc++.h>

using namespace std;

int m, n, k;

long long gcd(long long a, long long b) {return !b ? a : gcd(b, a % b);}

long long read()
{
	register char c = getchar();
	register long long p = 1, ans = 0;
	while (!isdigit(c))
	{
		if (c == '-') p = -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		ans = ans * 10 + c - 48;
		c = getchar();
	}
	return ans * p;
}

long long a, b;

int main()
{
#ifdef CraZYali
	freopen("wcd.in", "r", stdin);
	freopen("wcd.out", "w", stdout);
#endif
	cin >> n;
	long long x;
	REP(i, 1, n)
	{
		a = read();b = read();
		if (i == 1) x = a * b / gcd(a, b);
		else x = gcd(x, a * b / gcd(a, b));
	}
	
	if (x == 1) cout << -1;
	else cout << x;

	return 0;
}
