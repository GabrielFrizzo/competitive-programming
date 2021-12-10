#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 26;
const int INF = 1e8+5;

int dist[MxN][MxN];

void solve() {
	for (int i = 0; i < MxN; ++i)
		for (int j = 0; j < MxN; ++j)
			dist[i][j] = i == j ? 0 : INF;

	string s;
	cin >> s;
	int K;
	cin >> K;

	while (K--) {
		char Ai, Bi;
		cin >> Ai >> Bi;

		dist[Ai-'A'][Bi-'A'] = 1;
	}

	for (int i = 0; i < MxN; ++i)
		for (int j = 0; j < MxN; ++j)
			for (int k = 0; k < MxN; ++k)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);


	int best = INF;
	for (int objective = 0; objective < MxN; ++objective) {
		int total = 0;
		bool failed = false;
		for (char c : s) {
			if (dist[c-'A'][objective] == INF) {
				failed = true;
				break;
			}

			total += dist[c-'A'][objective];
		}

		if (!failed) {
			best = min(best, total);
		}
	}

	cout << (best == INF ? -1 : best);
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}