#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
const int MxN = 112345;
vi g[MxN];
int vis[MxN], cam[MxN];
bool res[MxN];
bool stacked[MxN];
int N, M, T;

void dfs(int u) {
  if (vis[u] == 1) return;
  if (cam[u] > 1) return;
  vis[u] = 1; cam[u]++;
  for (int v : g[u])
      dfs(v);
  vis[u] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M >> T;
	
	for (int i =0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		g[b].push_back(a);
	}

	for (int i: g[T]) {
		res[i] = true;
	}

	dfs(T);

	vi ans;
	for (int i = 0; i < N; ++i) {
		if (res[i] && cam[i] == 1) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << endl;
	for (int i : ans) {
		cout << i << endl;
	}
}

