#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using ll = long long;
int M;

void solve() {
	cin >> M;
	vector<pii> r(M);
	for (int i = 0; i < M; ++i) {
		cin >> r[i].second >> r[i].first;
	}

	sort(r.begin(), r.end());

	vi pref(M);
	pref[0] = 0;
	for (int i = 1; i < M; ++i) {
		pref[i] = pref[i-1] + r[i-1].second;
	}
	int stop;
	for (stop = 1; stop < M; ++stop) {
		if (pref[stop-1] < r[stop].first) break;
	}

	cout << M - stop << endl;

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