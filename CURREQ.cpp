#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;

LL gcd(LL a, LL b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

void solve()
{
	LL s, x, y, t;
	cin >> s >> x >> y >> t;

	LL a = s / gcd(x, s);
	LL tmp = (a*x) / s;
	tmp *= t;
	a *= y / gcd(y, tmp);

	LL b = (a * x) / s;
	LL c = (b * t) / y;
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
		solve();
	return 0;
}