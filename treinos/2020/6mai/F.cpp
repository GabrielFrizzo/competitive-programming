#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112;

int N, M;
int par[MxN];
int wei[MxN][MxN];

int bfs(vector<int>& graph, int s, int t) {
	vi dist(N, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int v : graph[u]) {
			if (wei[u][v] > 0 && dist[v] == INF) {
				dist[v] = dist[u]+1;
				q.push(v);
				p[v] = u;
			}
		}
	}

	for (int u = t; u != s; u = p[u]) {
		graph[]
	}
}

void solve() {
	vector<vector<pii>> graph(N+1);

	for (int i = 0;i < M; ++i) {
		int u, v, cost;
		cin >> u >> v >> cost;
		graph[u].push_back({v, cost});
		graph[v].push_back({u, cost});
	}

	ll mf = 0;
	while (true) {

	}


}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N >> M)
    	solve();
	return 0;
}