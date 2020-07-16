#include <bits/stdc++.h>
using namespace std;
#define MxN 2123
int N, M;
int graph[MxN][MxN];
int visited[MxN];

int dfs(int i, int trans) {
	if (visited[i]) return 0;
	visited[i] = 1;
	int res = 1;
	for (int j = 1; j <= N; ++j) {
		if ((trans && graph[j][i]) || (!trans && graph[i][j])) {
			res += dfs(j, trans);
		}
	}

	return res;
}


void solve() {
	memset(graph, 0, sizeof(graph));
	
	for (int i = 0; i < M; i++) {
		int v, w, p;
		cin >> v >> w >> p;
		graph[v][w] = 1;
		if (p==2) graph[w][v] = 1;
	}
	memset(visited, 0, sizeof(visited));
	int res = dfs(1,0);
	memset(visited, 0, sizeof(visited));
	cout << (res == N && dfs(1, 1) == N) << endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> N >> M, N) {
    	solve();
    }

	return 0;
}