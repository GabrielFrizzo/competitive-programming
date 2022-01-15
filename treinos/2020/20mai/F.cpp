#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using adjlist = vector<unordered_set<int>>;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int MxN = 112;
int N, res;

int dfs_low[MxN], dfs_num[MxN], dfs_parent[MxN], dfscurr, root, root_C;
adjlist graph;
unordered_set<int> points;

void artpoints(int u) {
	if (dfs_num[u] != -1) return;
	dfs_low[u] = dfs_num[u] = dfscurr++;

	for (int v : graph[u]) {
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == root) root_C++;

			artpoints(v);
			
			if (dfs_low[v] >= dfs_num[u])
				points.insert(u);

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

void solve() {
	graph.assign(N, unordered_set<int>());
	int u, v;
	while (cin >> u, u) {
		u--;
		string line;
		getline(cin, line);
		stringstream ss(line);
		while (ss >> v) {
			v--;
			graph[u].insert(v);
			graph[v].insert(u);
		}
	}

	res = dfscurr = 0;
	points.clear();
	memset(dfs_low, -1, sizeof(dfs_low));
	memset(dfs_num, -1, sizeof(dfs_num));
	memset(dfs_parent, -1, sizeof(dfs_parent));
	for (int i = 0; i < N; ++i) {
		if (dfs_num[i] == -1) {
			root = i; root_C = 0;
			artpoints(i);
			if (root_C > 1) points.insert(root);
			else if(points.count(root)) points.erase(root);
		}
	}
	debug() << imie(points);
	cout << points.size() << endl;
}

int main(int argc, char const *argv[])
{
	while (cin >> N, N)
		solve();

	return 0;
}