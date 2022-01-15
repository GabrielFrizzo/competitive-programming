#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
using vi = vector<int>;
using ll = long long;
using adjlist = vector<unordered_map<int, int>>;

const int MxN = 512;
const int INF = 1e9+5;

int N, M;
int S, D;
unordered_set<int> par[MxN];

void dijkstramod(adjlist& graph) {
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	pq.push({0, {S, S}});
	vi dist(N, INF);
	dist[S] = 0;

	while (!pq.empty()) {
		int u, cost, p;
		piii curr = pq.top(); pq.pop();
		cost = curr.first; tie(u, p) = curr.second;
		if (cost > dist[u]) continue;
		// cout << p << " parent " << u << " cost: " << cost << endl;
		par[u].insert(p);


		for (pii vv : graph[u]) {
			int v, vcost;
			tie(v, vcost) = vv;
			int ncost = dist[u] + vcost;
			if (ncost <= dist[v]) {
				dist[v] = ncost;
				pq.push({ncost, {v, u}});
			}
		}
	}
}

void eraseparents(adjlist& graph, int v) {
	for (int u : par[v]) {
		if (graph[u].erase(v)) {
			// cout << u << " " << v << endl;
			eraseparents(graph, u);
		}
	}
}

int dijkstra(adjlist& graph) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, S});
	vi dist(N, INF); dist[S] = 0;
	while (!pq.empty()) {
		int u, cost;
		tie(cost, u) = pq.top(); pq.pop();
		if (u == D) return cost;
		if (cost > dist[u]) continue;

		for (auto vv : graph[u]) {
			int v, vcost;
			tie(v, vcost) = vv;
			int ncost = dist[u] + vcost;
			if (ncost < dist[v]) {
				dist[v] = ncost;
				pq.push({ncost, v});
			}
		}
	}

	return -1;
}


void solve() {
	cin >> S >> D;

	adjlist graph(N);
	for (int i = 0; i < M; ++i) {
		int u, v, p;
		cin >> u >> v >> p;
		graph[u][v] = p;
	}

	for (int i = 0; i < N; ++i) par[i].clear();
	dijkstramod(graph);
	// for (int i = 0; i < N; ++i) {
	// 	cout << i << ": ";
	// 	for (int j : par[i])
	// 		cout << j << " ";
	// 	cout << endl;
	// }
	eraseparents(graph, D);
	cout << dijkstra(graph) << endl;
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