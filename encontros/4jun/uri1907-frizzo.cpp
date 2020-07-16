#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int n, m;
vector<vector<char>> graph;
vector<pii> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j) {
	return i >= 0 and j >= 0 and i < n and j < m;
}

bool dfs(int i, int j) {
	if (graph[i][j] == 'o') return false;
	graph[i][j] = 'o';

	for (pii d : directions) {
		if (valid(d.first+i, d.second+j))
			dfs(d.first+i, d.second+j);
	}

	return true;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

	graph.assign(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> graph[i][j];    	
    	}
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ans += dfs(i, j);


	cout << ans << endl;
	return 0;
}