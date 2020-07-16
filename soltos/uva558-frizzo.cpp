#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using adjlist = vector<unordered_map<int,int>>;

const int INF = 1e9 + 5;

void solve() {
	int n, m;
	cin >> n >> m;

	adjlist graph(n);
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u][v] = c;
	}

	vi dist(n, INF);

	for (int i = 0; i < n-1; ++i) {
		for (int u = 0; u < n; ++u) {
			for (pii p : graph[u]) {
				int v, cost;
				tie(v, cost) = p;
				//relax uv
				dist[v] = min(dist[v], dist[u]+cost);
			}
		}
	}


	bool good = true;
	for (int u = 0; u < n && good; ++u) {
		for (pii p : graph[u]) {
			int v, cost;
			tie(v, cost) = p;
			//relax uv
			if (dist[u]+cost < dist[v]) {
				good = false; break;
			}
		}
	}

	cout << (good ? "not possible" : "possible") << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) solve();
	return 0;
}