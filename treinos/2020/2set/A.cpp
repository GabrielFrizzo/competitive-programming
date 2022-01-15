#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vc = vector<char>;

void solve() {
	int N;
	cin >> N;
	vc v(N), vv(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	int total = 0;
	for (int i = 0; i < N; ++i) {
		char inp;
		cin >> inp;
		total += inp == v[i];
	}
	vi w(N+1);
	for (int i = 0; i <= N; ++i) {
		cin >> w[i];
	}

	if (total == N) {
		cout << w[N] << endl;
		return;
	}

	int best = 0;
	for (int i = 0; i <= total; ++i) {
		best = max(best, w[i]);
	}

	cout << best << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;
	while(TC--) {
		solve();
	}
	return 0;
}