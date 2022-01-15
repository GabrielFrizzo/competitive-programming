#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vi v(m);
	for (int i = 0; i < m; ++i) {
		cin >> v[i];
	}

	vi suff(m);
	ll total = 0;
	for (int i = m-1; i >= 0; --i) {
		total += v[i];
		suff[i] = total;
	}

	if (suff[0] < n) { cout << -1 << endl; return 0; }
	for (int i = 0; i < m; ++i) {
		if (n-v[i] < i) { cout << -1 << endl; return 0; }
	}

	for (ll i = 0; i < m; ++i) {
		cout << max(i+1, n - suff[i] + 1);
		if (i != m-1) cout << ' ';
	}
	cout << endl;

	return 0;
}