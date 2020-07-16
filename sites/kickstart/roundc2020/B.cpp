#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using adjlist = vector<unordered_set<int>>;

vector<int> toposort;
adjlist graph;
vector<bool> visited, running;
bool good;

void dfs(int u) {
	if (running[u]){ good = false; return;}
	if (visited[u]) return;
	visited[u] = true;
	running[u] = true;
	for (int i : graph[u]) {
		dfs(i);
	}
	running[u] = false;
	toposort.push_back(u);
}

void solve() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> inp(R, vector<int>(C));
    set<int> allv;
    for (int i = 0; i < R; ++i) {
    	for (int j = 0; j < C; ++j) {
    		char c;
    		cin >> c;
    		int n = c-'A';
    		inp[i][j] = n;
    		allv.insert(n);
    	}
    }
    graph.assign(26, unordered_set<int>());
	for (int i = 0; i < R-1; ++i) {
    	for (int j = 0; j < C; ++j) {
    		int curr = inp[i][j];
    		int below = inp[i+1][j];
    		if (curr!=below) {
    			graph[curr].insert(below);
    		}
    	}
    }

    visited.assign(26, false);
    running.assign(26, false);
    good = true;
    toposort.clear();
    for (int i : allv)
    	dfs(i);

    if (good) {
		for (int i : toposort) {
			cout << (char)('A'+i);
		}
    } else {
    	cout << -1;
    }
    cout << endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	solve();
    }
	return 0;
}