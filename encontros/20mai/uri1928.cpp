#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int n, l;
vector<vi> adj;

int timer;
vi tin, tout, height;
vector<vi> up;

void dfs(int v, int p) {
	height[v] = height[p]+1;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    height.resize(n);
    height[root] = -1;
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vi(l + 1));
    dfs(root, root);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pii> cards(n/2, {-1,-1});
    for (int i = 0; i < n; ++i) {
    	int inp;
    	cin >> inp; inp--;
    	if (cards[inp].first == -1) cards[inp].first = i;
    	else cards[inp].second = i;
    }

    adj.assign(n, vi());
    for (int i = 0; i < n-1; ++i) {
    	int a, b;
    	cin >> a >> b; a--; b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    preprocess(0);

    int res = 0;
    for (pii p : cards) {
    	int u, v, w;
    	tie(u, v) = p;
    	w = lca(u, v);
    	res += height[u] + height[v] - 2*height[w];
    }

    cout << res << endl;

	return 0;
}