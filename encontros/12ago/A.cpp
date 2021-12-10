#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int MxN = 512;
const int INF = 1e9+7;

int n, m, q;
vi g[MxN];
int age[MxN], vert[MxN];
bool vis[MxN];
int _min;

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;

	for (int v : g[u]) {
		_min = min(_min, age[v]);
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m >> q) {
		for (int i = 0; i < MxN; ++i) {
			g[i].clear();
		}
		for (int u = 0; u < n; ++u) {
			cin >> age[u];
			vert[u] = u;
		}

		while (m--) {
			int u, v;
			cin >> u >> v; u--; v--;
			g[v].push_back(u);
		}

		while (q--) {
			char op;
			cin >> op;
			int a, b;
			if (op == 'T') {
				cin >> a >> b; a--; b--;
				swap(vert[a], vert[b]);
				swap(age[vert[a]], age[vert[b]]);
			} else if (op == 'P') {
				cin >> a; a--;
				_min = INF;
				memset(vis, false, sizeof(vis));
				dfs(vert[a]);
				if (_min == INF) {
					cout << '*' << endl;
				}
				else {
					cout << _min << endl;
				}
			}
		}
	}

	return 0;
}