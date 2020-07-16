#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using uset = unordered_set<int>;
using adjlist = vector<unordered_map<int, int>>;

#define S 0
#define T 1
const int MxN = 112;
const int INF = 1e9+5;
int N, Q;
int K;
bool parents[MxN][MxN];
int par[MxN+MxN+2];

bool bfs(adjlist& graph) {
	vi dist(2+N+N, INF); dist[S] = 0;
	queue<int> q; q.push(S);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == T) return true;
		for (pii vv : graph[u]) {
			int v = vv.first;
			int vsize = vv.second;
			if (vsize > 0 && dist[v] == INF) {
				dist[v] = dist[u]+1;
				q.push(v);
				par[v] = u;
			}
		}
	}

	return false;
}

bool ffek(adjlist& graph) {
	int total = 0;
	while (bfs(graph)) {
		// for (unordered_map<int,int> u : graph) {
		// 	for (pii vv : u) {
		// 		cout << vv.first << ":" << vv.second << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		for (int u = T; u!=S; u=par[u]) {
			graph[par[u]][u] -= 1;
			graph[u][par[u]] += 1;
		}
		total++;
	}

	return total == N;
}

void query() {
	cin >> K;
	adjlist graph(N+N+2);
	vector<int> childgenes; childgenes.push_back(0);
	for (int i = 2+N; i < 2+N+K; ++i) {
		int j;
		cin >> j;
		childgenes.push_back(j);
		graph[S][i] = 1; // child supernode
		graph[i][S] = 0;
		for (int p = 0; p < N; ++p) {
			if (parents[p][j]) {
				graph[i][p+2] = 1;
				graph[p+2][i] = 0;
			}
		}
	}

	// O aleles
	if (K < N) {
		for (int i = 2+N+K; i < 2+N+N; ++i) {
			graph[S][i] = 1; // child supernode
			graph[i][S] = 0;
			for (int j : childgenes) {
				for (int p = 0; p < N; ++p) {
					if (parents[p][j]) {
						graph[i][p+2] = 1;
						graph[p+2][i] = 0;
					}
				}
			}
		}
	}

	// parent supernode
	for (int i = 2; i < N+2; ++i) {
		graph[i][T] = 1;
		graph[T][i] = 0;
	}

	cout << (ffek(graph) ? 'Y' : 'N') << endl;

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    memset(parents, false, sizeof(parents));

    for (int i = 0; i < N; ++i) {
    	cin >> K;
    	if (K < N) parents[i][0] = true;
    	while(K--) {
    		int j;
    		cin >> j;
    		parents[i][j] = true;
    	}
    }

    while (Q--) {
    	query();
    }
	return 0;
}