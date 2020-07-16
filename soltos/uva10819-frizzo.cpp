// HaHa3.5 - Knapsack

#include <bits/stdc++.h>
using namespace std;

int m, n;
int costs[112], values[112];
int dp[112][11234][2];

int solve(int item, int remaining, bool credited) {
	bool c = credited;
	if (remaining < 0) {
		if (credited) return -9999;
		else {
			remaining += 200;
			c = true;
		}
	}
	if (dp[item][remaining][c] != -1) return dp[item][remaining][c];

	if (remaining <= 0 && !c) return dp[item][remaining][c] = 0;
	if (item == n && c && m+200-remaining <= 2000)
		return -9999;
	if (item == n) return dp[item][remaining][c] = 0;
	if ((costs[item] > remaining + 200) ||
		(costs[item] > remaining && m <= 1800)) return solve(item+1, remaining, credited);

	return dp[item][remaining][c] =
		max(solve(item+1, remaining, credited),
			solve(item+1, remaining - costs[item], c) + values[item]);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);


    while (cin >> m >> n) {
    	memset(dp, -1, sizeof(dp));
    	for (int i = 0; i<n; i++) {
    		cin >> costs[i] >> values[i];
    	}


    	cout << max(0, solve(0, m, false)) << endl;
    }

	return 0;
}

// 500 4
// 100 2
// 100 3
// 200 3
// 400 4
// 2000 5
// 1000 2
// 100 3
// 200 3
// 800 4
// 3000 1
