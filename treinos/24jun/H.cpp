#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112345;

vi g[MxN];
bool vis[MxN];
int N, M;

int bfs() {
	queue<pii> q;
	q.push({1, 0});

	while (!q.empty()) {
		int u, d;
		tie(u, d) = q.front(); q.pop();
		// cout << 'u' << u << endl;
		if (u == N) return d;
		if (vis[u]) continue;
		vis[u] = true;
 		for (int v : g[u]) {
 			// cout << 'v' << v << endl;
			if (!vis[v])
				q.push({v, d+1});
		}
	}
	assert(false);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    cout << bfs()-1 << endl;

	return 0;
}