#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 11234;
const int MOD = 1e9 + 7;


int imp[MxN];
int g[MxN][MxN];
int N, C;

int dfs(int u, int p) {
	int total = 0;
	for (int v = 1; v <= N; ++v) {
		if (v != p && g[u][v]) {
			total += dfs(v, u);
			imp[u] += imp[v];
			total += g[u][v] * 2 * ceil(imp[v]/(double)C);
		}
	}
	// cout << u << ' ' << total << endl;

	return total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;

	for (int i = 1; i <= N; ++i) {
		cin >> imp[i];
	}
	imp[1] = 0;

	for (int i = 2; i <= N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = c;
		g[b][a] = c;
	}

	cout << dfs(1, 1) << endl;

	return 0;
}