#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 11234;

int N, M;
set<int> graph[MxN];
bool vis[MxN];
vi tree[MxN];
vector<tuple<int, int, int>> ans;

void dfs(int u) {
	for (int v : graph[u]) {
		if (!vis[v]) {
			vis[v] = true;
			tree[u].push_back(v);
			dfs(v);
		}
	}
}

void dfs2(int u, int par) {
	for (int v : tree[u]) {
		dfs2(v, u);
	}

	// process node
	int deg = graph[u].size();
	int prev = -1;
	for (int v : graph[u]) {
		if (!(deg&1 && v==par)) {
			graph[v].erase(u);
			if (prev == -1) prev = v;
			else {
				ans.push_back({prev, u, v});
				prev = -1;
			}
		}
	}
	assert(prev = -1);
	graph[u].clear();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
    	int u, v;
    	cin >> u >> v;
    	graph[u].insert(v);
    	graph[v].insert(u);
    }

    vis[1] = true;
    dfs(1);

    dfs2(1, -1);

    cout << ans.size() << endl;
    for (auto tup : ans) {
    	int u, v, w;
    	tie(u, v, w) = tup;
    	cout << u << ' ' << v << ' ' << w << endl;
    }
	return 0;
}