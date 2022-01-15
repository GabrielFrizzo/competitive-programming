#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 212345;

ll life[MxN];
vector<int> g[MxN];
int n, t;
int solution[MxN];
int solution_rev[MxN];


bool dfs(int u, int p) {
	if (u == t) return true;
	for (int v : g[u]) {
		if (v != p && dfs(v, u)) {
			solution[u] = v;
			solution_rev[v] = u;
			return true;
		}
	}

	return false;
}

ll update(int u, int p) {
	ll total = life[u];

	for (int v : g[u]) {
		if (v != p && solution[u] != v && solution_rev[u] != v) {
			ll nxt = update(v, u);
			if (nxt > 0) total += nxt;
		}
	}

	return life[u] = total;
}

bool dfs(int u, ll left, int p) {
	left += life[u];
	if (left < 0) return false;
	if (u == t) return true;
	
	return dfs(solution[u], left, u);
}

void solve() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i) g[i].clear();

	for (int i = 1; i <= n; ++i) {
		cin >> life[i];
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	memset(solution, -1, sizeof solution);
	memset(solution_rev, -1, sizeof solution_rev);
	dfs(1, 1);

	int curr = 1;
	while (curr != t) {
		update(curr, curr);
		curr = solution[curr];
	}

	for (int i = 1; i <= n; ++i) cout << life[i] << endl;

	cout << (dfs(1, 0, 1) ? "escaped" : "trapped") << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
    	solve();
    }
	return 0;
}