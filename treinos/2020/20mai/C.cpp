#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using uset = unordered_set<int>;

const int INF = 1e9+5;
const int MxN = 1123;

struct cab {
	int a, b, c, d, time;
	cab() {}
	cab(int _a, int _b, int _c, int _d, int _time): a(_a), b(_b), c(_c), d(_d), time(_time) {}

	bool cango(const cab& other) {
		int d1x = abs(a-c), d1y = abs(b-d), d2x = abs(c-other.a), d2y = abs(d-other.b);
		return (other.time - time) > d1x+d1y+d2x+d2y;
	}
};

int N;
uset vin, vout;
vector<uset> graph;

int match[MxN], dist[MxN];

bool bfs() {
	queue<int> q;
	int k = INF;

	for (int u : vout) {
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
	for (int i = 0; i < N; ++i) match[i] = i;
	int matching = 0;

	while (bfs()) {
		for (int v : vout) {
			if (match[v] == v && dfs(v))
				matching++;
		}
	}

	return matching;
}

void solve() {
	int M;
	scanf(" %d", &M);
	N = M*2;
	graph.assign(M, uset());
	vout.clear(); vin.clear();
	vector<cab> cabs;
	for (int i = 0; i < M; ++i) {
		int hh, mm, a, b, c, d;
		scanf(" %d:%d %d %d %d %d", &hh, &mm, &a, &b, &c, &d);
		cabs.push_back(cab(a, b, c, d, hh*60+mm));
		for (int j = 0; j < i; ++j) {
			if (cabs[j].cango(cabs[i])) {
				graph[j].insert(i+M);
				vout.insert(j);
				vin.insert(i+M);
			}
		}
	}

	// for (int i = 0; i < N; ++i) {
	// 	for (int j : graph[i]) {
	// 		cout << j << ' ';
	// 	}
	// 	cout << endl;
	// }
	printf("%d\n", M - hkarp());
}

int main(int argc, char const *argv[])
{
    int TC;
    scanf(" %d", &TC);

    while (TC--) {
    	solve();
    }
	return 0;
}