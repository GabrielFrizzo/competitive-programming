#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
const int MxN = 112345;
vi g[MxN];
int vis[MxN];
bool res[MxN];
bool stacked[MxN];
int N, M, T;

void dfs(int u) {
	if (stacked[u]) {
		return;
	}
	if (vis[u] == 2 || u == T) {
		return;
	}
	vis[u]++;

	stacked[u] = true;
	for (int v : g[u]) {
		dfs(v);
	}
	stacked[u] = false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M >> T;
	
	for (int i =0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		g[b].push_back(a);
	}

	for (int i: g[T]) {
		res[i] = true;
	}

	for (int i : g[T]) {
		dfs(i);
	}

	vi ans;
	for (int i = 0; i < N; ++i) {
		if (vis[i] == 1) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << endl;
	for (int i : ans) {
		cout << i << endl;
	}
}

