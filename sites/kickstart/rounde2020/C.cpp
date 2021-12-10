#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;
const ll INF = 1e16;

int M;
ll test(int i, vi& e, vi& r) {
	int cop = i;
	ll elapsed = 0;
	vector<ll> vis(M, -1);
	for (int j = 0; j < M; ++j) {
		if (cop&1) {
			if (vis[j] != -1 && elapsed - vis[j] < r[j]) {
				return elapsed;
			}
			elapsed += e[j];
			vis[j] = elapsed;
		}
		cop >>= 1;
	}

	cop = i;
	for (int j = 0; j < M; ++j) {
		if (cop&1) {
			if (vis[j] != -1 && elapsed - vis[j] < r[j]) {
				return elapsed;
			}
			elapsed += e[j];
		}
		cop >>= 1;
	}

	return INF;
}

int cnt(int i) {
	int res = 0;
	while (i) {
		res += i&1;
		i >>= 1;
	}
	return res;
}

void solve() {
	cin >> M;
	vi e(M), r(M);
	for (int i = 0; i < M; ++i) {
		cin >> e[i] >> r[i];
	}

	int besti = 0;
	ll best = 0;
	for (int i = 1; i < 1<<M; ++i) {
		ll res = test(i, e, r);
		if (res > best) {
			besti = cnt(i);
			best = res;
		} else if (res == best) {
			besti = max(cnt(i), besti);
		}
	}
	if (best == INF) {
		cout << M - besti << ' ' << "INDEFINITELY\n";
	} else {
		cout << M - besti << ' ' << best << endl;
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}