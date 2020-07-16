#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using adjlist = unordered_map<int, unordered_set<int>>;

int N;
vector<bool> visited;
vi match;

bool aug(adjlist& graph, int u) {
	if (visited[u]) return false;
	visited[u] = true;
	for (int v : graph[u]) {
		if (match[v] == -1 || aug(graph, match[v])) {
			match[v] = u; return true;
		}
	}
	return false;
}

void solve() {
	vector<vector<char>> mat(N, vector<char>(N));
	vector<vi> lines(N, vi(N)), cols(N, vi(N));
	int nline = 0; bool newl = true;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == 'X') newl = true;
			else {
				nline += newl;
				lines[i][j] = nline;
				newl = false;
			}
		}
		newl = true;
	}

	int ncol = 0;
	newl = true;
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i) {
			if (mat[i][j] == 'X') newl = true;
			else {
				ncol += newl;
				cols[i][j] = ncol;
				newl = false;
			}
		}
		newl = true;
	}

	adjlist graph;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int l = lines[i][j], c = cols[i][j];
			if (l!=0) {
				assert(c!=0);
				graph[l].insert(c);
			}
		}
	}

	int res = 0;
	match.assign(ncol+1, -1);
	for (int u = 1; u <= nline; ++u) {
		visited.assign(nline+1, 0);
		res += aug(graph, u);
	}

	cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N) {
    	solve();
    }

	return 0;
}