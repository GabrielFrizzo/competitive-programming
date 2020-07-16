#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using piii = pair<int, pii>;

const int MxN = 512;
const int INF = 1e9+5;

int N, M;
int S, D;
int visited[MxN];
set<int> par[MxN];
int graph[MxN][MxN];

void eraseedges() {
	for (int i = D; i != S && graph[par[i]][i] != -1; i = par[i]) {
		graph[par[i]][i] = -1;
	}
}

void dijkstramod() {
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	pq.push({0, {S, S}});
	vi dist(N, INF);
	int found = INF;

	while(!pq.empty()) {
		piii curr = pq.top(); pq.pop();
		int u = curr.second.first;
		par[u].insert(curr.second.second);
		if (u == D) {
			found = curr.first;
			eraseedges();
			continue;
		}
		if (visited[u]) continue;
		visited[u] = true;

		for (int v = 0; v < N; ++v) {
			int ndist = dist[u] + graph[u][v];
			if (graph[u][v] != -1 && ) {
				pq.push({curr.first+graph[u][v], {v, u}});
			}
		}
	}

	return -1;
}

int dijkstra() {
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	pq.push({0, {S, S}});

	while(!pq.empty()) {
		piii curr = pq.top(); pq.pop();
		int u = curr.second.first;
		if (u == D) return curr.first;
		if (visited[u]) continue;
		visited[u] = true;

		for (int v = 0; v < N; ++v) {
			if (graph[u][v] != -1) {
				pq.push({curr.first+graph[u][v], {v, u}});
			}
		}
	}

	return -1;
}


void solve() {
	cin >> S >> D;

	memset(graph, -1, sizeof(graph));
	for (int i = 0; i < M; ++i) {
		int u, v, p;
		cin >> u >> v >> p;
		graph[u][v] = p;
	}

	memset(visited, 0, sizeof(visited));
	memset(par, 0, sizeof(par));
	int best = dijkstramod();
	// cout << best << endl;
	memset(visited, 0, sizeof(visited));
	int second = dijkstra();

	cout << (second < 0 ? -1 : second) << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> N >> M, N) {
    	solve();
    }

	return 0;
}