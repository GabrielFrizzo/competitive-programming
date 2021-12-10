#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int MxN = 51;

int memo[MxN][MxN][MxN];
vi g[MxN];
vi stones[MxN];
int recipes[MxN][MxN];
int rec_res[MxN];


void solve() {
	int N, M, S, R;
	cin >> N >> M >> S >> R;

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i) {
		int inp;
		cin >> inp;
		while (inp--) {
			cin >> inp2;
			stones[i].push_back(inp2);
		}
	}

	for (int i = 0; i < R; ++i) {
		int inp;
		cin >> inp;
		while(inp--) {
			cin >> recipes[i][inp];
		}
		cin >> rec_res[i];
	}

}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}