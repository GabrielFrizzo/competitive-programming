#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int N;
void solve() {
	vector<string> all;
	for (int i = 0; i < N; ++i) {
		string inp;
		cin >> inp;
		all.push_back(inp);
	}
	sort(all.begin(), all.end());
	int k = all[0].size();
	int total = 0;
	for (int j = 1; j < N; ++j) {
		for (int i =0; i < k; ++i) {
			if (all[j-1][i] == all[j][i])
				total++;
			else
				break;
		}
	}

	cout << total << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N) {
		solve();
	}

	return 0;
}