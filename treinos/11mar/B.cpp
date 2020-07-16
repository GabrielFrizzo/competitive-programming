#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int N, M;

vector<vector<char>> graph;
vector<vector<bool>> visited;
vector<pii> directions = {{0,1}, {-1,0}, {1,0}, {0,-1}};
bool valid(int i, int j) {return i >= 0 && j >= 0 && i < N && j < M; }

void dfs(int i, int j) {
	if (visited[i][j]) return;
	visited[i][j] = true;
	if (graph[i][j] == 'A')
		graph[i][j] = 'T';
	for (pii d : directions) {
		int r = i+d.first, c = j+d.second;
		if (valid(r, c) && graph[r][c] != 'X')
			dfs(r, c);
	}
}

void solve() {
	graph.assign(N, vector<char>(M));
	visited.assign(N, vector<bool>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (graph[i][j] == 'T')
				dfs(i, j);
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << graph[i][j];
		}
		cout << endl;
	}
	cout << endl;
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