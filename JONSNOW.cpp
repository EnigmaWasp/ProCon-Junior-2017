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

void solve()
{
	int n, m;
	cin >> n >> m;
	LL strA = 0;
	LL strB = 0;
	LL a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		strA += a;
	}
		
	for (int i = 0; i < m; i++)
	{
		cin >> b;
		strB += b;
	}

	if (strA >= strB) cout << "Snow" << endl;
	else cout << "Death" << endl;

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