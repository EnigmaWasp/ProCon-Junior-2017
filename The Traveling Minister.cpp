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
typedef vector<int> vi;

const int MaxN = 100 * 1000;
pii flights[MaxN + 10];

bool comp(pii a, pii b)
{
	return a.second < b.second || (a.second == b.second && a.first > b.first);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;
	set<int> nums;
	for (int i = 0; i < n; i++)
	{
		cin >> flights[i].first >> flights[i].second;
		nums.insert(flights[i].first);
		nums.insert(flights[i].second);
	}

	int maxDay = 0;
	map<int, int> days;
	{
		int i = 0;
		while (nums.size() > 0)
		{
			i++;
			days[*nums.begin()] = i;
			nums.erase(nums.begin());
		}
		maxDay = i;
	}

	for (int i = 0; i < n; i++)
	{
		flights[i].first = days[flights[i].first];
		flights[i].second = days[flights[i].second];
	}

	sort(flights, flights + n, comp);
	vi dp(maxDay + 10, 0);

	{
		int i = 0;
		for (int day = 1; day <= maxDay; day++)
		{
			dp[day] = dp[day - 1];
			while (day == flights[i].second)
			{
				dp[day] = max(dp[day], dp[flights[i].first - 1] + 1);
				i++;
			}
		}
	}

	cout << dp[maxDay] << endl;

	return 0;
}
