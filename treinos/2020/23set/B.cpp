#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MxN = 3123;

int dist[MxN], p[MxN];
vi g[MxN];
int n;

void dfs(int u, int par) {
	dist[u] = dist[par] + 1;
	for (int v : g[u]) {
		if (v != par) {
			p[v] = u;
			dfs(v, u);
		}
	}
}

pii achameio(int u) {
	dfs(u, u);

	int ext = u;
	for (int i = 0; i < n-1; ++i) {
		ext = dist[i] > dist[ext] ? i : ext;
	}

	dfs(ext, ext);
	ext = 0;
	for (int i = 0; i < n-1; ++i) {
		ext = dist[i] > dist[ext] ? i : ext;
	}

	int mid = ext;
	for (int i = 0; i < dist[ext]/2; ++i) {
		mid = p[mid];
	}

	return {mid, ext};
}

void solve() {
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int mid, ext;
	tie(mid, ext) = achameio(0);
	

	cout << dist[ext] << endl;
	cout << mid+1 << ' ' << p[mid]+1 << endl;

	tie(mid, ext) = achameio(mid);
	cout << mid+1 << ' ';

	tie(mid, ext) = achameio(mid+1);
	cout << mid+1 << endl;


	// TODO SOMAR 1 NO FINAL
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}