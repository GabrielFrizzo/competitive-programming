#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112;
const int INF = 1e9+5;

int N, s, t, M;
int graph[MxN][MxN], p[MxN];

int bfs() {
	vi dist(N, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int v = 0; v < N; ++v) {
			if (graph[u][v] > 0 && dist[v] == INF) {
				dist[v] = dist[u]+1;
				q.push(v);
				p[v] = u;
			}
		}
	}

	int bneck = INF;
	if (dist[t] == INF) return 0;
	for (int u = t; u != s; u = p[u]) {
		bneck = min(bneck, graph[p[u]][u]);
	}

	return bneck;
}

ll ffek() {
	ll f = 0;
	int bneck;
	while ((bneck = bfs())) {
		for (int u = t; u != s; u = p[u]) {
			graph[p[u]][u] -= bneck;
			graph[u][p[u]] += bneck;
		}
		f += bneck;
	}

	return f;
}

void solve(int TC) {
	memset(graph, 0, sizeof(graph));
	while (M--) {
		int u, v, cost;
		cin >> u >> v >> cost;
		u--;
		v--;
		graph[u][v] += cost;
		graph[v][u] += cost;
	}


	cout << "Network " << TC << endl;
	cout << "The bandwidth is " << ffek() << "." << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i = 0;
	while (cin >> N, N) {
		cin >> s >> t >> M;
		s--;
		t--;
		solve(++i);
		cout << endl;
	}

	return 0;
}