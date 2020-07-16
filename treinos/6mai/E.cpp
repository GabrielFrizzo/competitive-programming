#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using adjlist = vector<unordered_map<int,int>>;

const int INF = 1e9+5;

int n, m, L, s, t;
vi dist;
set<pii> iserased;

void dijkstra(adjlist& graph) {
	dist.assign(n, INF);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});

	while (!pq.empty()) {
		int u, cost;
		tie(cost, u) = pq.top(); pq.pop();
		if (cost > dist[u]) continue;

		for (pii p : graph[u]) {
			int v, vcost;
			tie(v, vcost) = p;
			if (dist[u] + vcost < dist[v]) {
				dist[v] = dist[u] + vcost;
				pq.push({dist[v], v});
			}
		}
	}
}

vi distmod;
void dijkstramod(adjlist& graph, int need) {
	distmod.assign(n, INF);
	distmod[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});

	while (!pq.empty()) {
		int u, cost;
		tie(cost, u) = pq.top(); pq.pop();
		if (cost > distmod[u]) continue;

		for (pii p : graph[u]) {
			int v, vcost;
			tie(v, vcost) = p;

			if (distmod[u] + vcost < distmod[v] &&
				iserased.count({u, v}) &&
				distmod[u] + vcost < dist[v] + need)
			{
				// cout << need << endl;
				vcost = graph[u][v] = graph[v][u] = dist[v] + need - distmod[u];
			}

			if (distmod[u] + vcost < distmod[v]) {
				distmod[v] = distmod[u] + vcost;
				pq.push({distmod[v], v});
			}
		}
	}
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> L >> s >> t;

    adjlist graph(n);
    vector<pii> edge_inp;

    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	edge_inp.push_back({u, v});
    	if (w == 0) {
    		iserased.insert({u, v});
    		iserased.insert({v, u});
    	}
    	graph[u][v] = graph[v][u] = w == 0 ? 1 : w;
    }

    dijkstra(graph);
    int need = L - dist[t];
    if (need < 0) {cout << "NO" << endl; return 0;}

    dijkstramod(graph, need);

    if (distmod[t] != L) {cout << "NO" << endl; return 0;}
    cout << "YES" << endl;
    for (pii p : edge_inp) {
    	cout << p.first << " " << p.second << " " << graph[p.first][p.second] << endl;
    }

	return 0;
}