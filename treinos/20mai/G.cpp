#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112345;

int N;
vi tree[MxN];
bool vis[MxN];
int cyclen[MxN], cycpos[MxN];

int dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = true;

	for (int v : tree[u]) {
		int cyc = dfs(v);
		if (cyc != -1) {
			
		}
	}

	return -1;
}

void query(int x, int y) {

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N) {
	    for (int v = 1; v <= N; ++v) {
	    	int u; cin >> u;
	    	tree[u].push_back(v);
	    }

	    memset(vis, false, sizeof vis);
	    memset(cyclen, -1, sizeof cyclen);
	    memset(cycpos, -1, sizeof cycpos);
	    for (int u = 1; u <= N; ++u)
	    	dfs(u);

	    int Q;
	    cin >> Q;
	    while (Q--) {
	    	int x, y;
	    	cin >> x >> y;
	    	query(x, y);
	    }
    }

	return 0;
}