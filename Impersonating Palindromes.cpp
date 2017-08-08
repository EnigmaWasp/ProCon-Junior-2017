#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;


void solve()
{
	int l, n;
	cin >> l >> n;
	map<char, int> color;
	for (char c = 'A'; c <= 'Z'; c++)
		color[c] = c;
	for (char c = 'a'; c <= 'z'; c++)
		color[c] = c;
	for (char c = '0'; c <= '9'; c++)
		color[c] = c;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		char c;
		for (int j = 1; j <= k; j++)
		{
			cin >> c;
			color[c] = i;
		}
	}

	for (int l = 0, r = s.length() - 1; l < r; l++,r--)
		if (color[s[l]] != color[s[r]])
		{
			cout << "Not Impersonating" << endl;
			return;
		}

	cout << "Impersonating" << endl;
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
