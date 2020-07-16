#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adj;
vector<int> res;
unordered_set<int> visited;

void dfs(int i) {
	if (visited.count(i)) return;
	visited.insert(i);
	for (int j : adj[i])
		dfs(j);

	res.push_back(i);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, inp1, inp2;
    while(cin >> n >> m, n) {
    	adj.clear();
    	res.clear();
    	visited.clear();
    	while (m--) {
    		cin >> inp1 >> inp2;
    		adj[inp1].push_back(inp2);
    	}
    	// for (int i = 1; i <= n; ++i) {
    	// 	for (int j : adj[i])
    	// 		cout << j << " ";
    	// 	cout << endl;
    	// }
    	for (int i = 1; i <= n; ++i)
    		dfs(i);
    	reverse(res.begin(), res.end());
    	for (int i : res)
    		cout << i << " ";
    	cout << endl;
    }
    
	return 0;
}