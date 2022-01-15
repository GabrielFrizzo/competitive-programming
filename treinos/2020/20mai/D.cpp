#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using adjlist = vector<unordered_set<int>>;

const int MxN = 11234;
const int INF = 1e9+5;

int N, M;
int match[MxN], dist[MxN];
vi Abip;
adjlist graph;

bool bfs() {
	queue<int> q;
	int k = INF;

	for (int u : Abip) {
		if (match[u] == u) {
			dist[u] = 0;
			q.push(u);
		} else {
			dist[u] = INF;
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (dist[u] >= k) continue;
		for (int v : graph[u]) {
			if (v == match[v] && k == INF)
				k = dist[u]+1;
			else if (dist[match[v]] == INF) {
				dist[match[v]] = dist[u] + 1;
				q.push(match[v]);
			}
		}
	}

	return k != INF;
}

bool dfs(int u) {
	for (int v : graph[u]) {
		if (match[v] == v || (dist[match[v]] == dist[u]+1 && dfs(match[v]))) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	}

	dist[u] = INF;
	return false;
}

int hkarp() {
	for (int i = 0; i < N*M; ++i) match[i] = i;
	int matching = 0;

	while (bfs()) {
		for (int v : Abip) {
			if (match[v] == v && dfs(v))
				matching++;
		}
	}

	return matching;
}

bool valid(int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; }

void solve() {
	int K;
	cin >> K;

	vector<vi> m(N, vi(M, 1));
	while (K--) {
		int a, b;
		cin >> a >> b;a--;b--;
		m[a][b] = 0;
	}

	graph.assign(N*M, unordered_set<int>());
	vector<pii> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
	for (int i = 0; i < N; ++i) {
		for (int j = i&1; j < M; j+=2) {
			if (m[i][j] == 0) continue;
			Abip.push_back(i*M+j);
			for (pii d : directions) {
				int r = i+d.first, c = j+d.second;
				if (valid(r, c) && m[r][c] == 1) {
					graph[i*M+j].insert(r*M+c);
				}
			}
		}
	}

	cout << hkarp() << endl;
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