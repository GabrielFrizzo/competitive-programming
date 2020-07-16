#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;

const int MxN = 30;

unordered_map<string, int> name_to_pos;
vector<string> names;
vector<unordered_set<int>> graph;

int dfs_num[MxN], dfs_low[MxN], stkd[MxN], comp[MxN], dfscurr, ncomp;
vi stk;

void tarjan(int u) {
	if (dfs_num[u] != -1) return;
	dfs_low[u] = dfs_num[u] = dfscurr++;
	stk.push_back(u);
	stkd[u] = 1;

	for (int v : graph[u]) {
		tarjan(v);
		if (stkd[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]) {
		int v;
		do {
			v = stk.back(); stk.pop_back();
			comp[v] = ncomp;
			stkd[v] = 0;
		} while (v != u);
		ncomp++;
	}
}

int insert_name(string& name) {
	if (name_to_pos.find(name) != name_to_pos.end()) return name_to_pos[name];
	names.push_back(name);
	return name_to_pos[name] = names.size() - 1;
}

void solve(int N, int M, int TC) {
	name_to_pos.clear();
	names.clear();
	graph.assign(N, unordered_set<int>());
	// create graph
	for (int i = 0; i < M; ++i) {
		string caller, receiver;
		cin >> caller >> receiver;
		int u = insert_name(caller);
		int v = insert_name(receiver);
		graph[u].insert(v);
	}

	//run tarjan
	memset(dfs_low, 0, sizeof(dfs_low));
	memset(dfs_num, -1, sizeof(dfs_num));
	memset(stkd, 0, sizeof(stkd));
	memset(comp, -1, sizeof(comp));
	stk.clear();
	dfscurr = ncomp = 0;
	for (int i = 0; i < N; ++i)
		tarjan(i);


	// show result
	vector<vector<string>> res(N);
	for (int i = 0; i < N; ++i) res[comp[i]].push_back(names[i]);

	cout << "Calling circles for data set " << TC << ":" << endl;
	for (vector<string> group : res) {
		if (!group.empty()) {
			bool start = true;
			for (string name : group) {
				if (!start) cout << ", ";
				cout << name;
				start = false;
			}
			cout << endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tc = 0;
    bool start = true;
    while (cin >> n >> m, n) {
    	if (!start) cout << endl;
    	solve(n, m, ++tc);
    	start = false;
    }
	return 0;
}