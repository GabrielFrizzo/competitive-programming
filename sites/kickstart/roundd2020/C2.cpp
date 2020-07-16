#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 512345;

int p[MxN];
bool vis[MxN];
vi g[MxN];
int na[MxN], nb[MxN];
int N, A, B;

int dfs(int u) {
	if (g[u].size() == 0) {
		return 1;	
	}
	na[u] = na[u] = 1;
	for (int v : g[u]) {
		int res = dfs(v);
		na[u] += res/A;
		nb[u] += res/B;
	}

	return total;
}

void solve() {
    cin >> N >> A >> B;
    for (int i = 2; i <= N; ++i) {
    	cin >> p[i];
    	g[p[i]].push_back(i);
    }
    p[1] = p[0] = 0;
    
    dfs(1);
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