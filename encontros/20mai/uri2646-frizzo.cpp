#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int N = 26;

void fwarshall(vector<vector<bool>>& graph) {
	for (int w = 0; w < N; ++w) {
		for (int u = 0; u < N; ++u) {
			for (int v = 0; v < N; ++v) {
				graph[u][v] = graph[u][v] || (graph[u][w] && graph[w][v]);
			}
		}
	}
}

bool query(vector<vector<bool>>& graph) {
	string a, b;
	cin >> a >> b;
	int S = a.size();
	if (S != b.size()) return false;;

	for (int i = 0; i < S; ++i) {
		// cout << a[i]-'a' << " " << b[i]-'a' << endl;
		if (graph[a[i]-'a'][b[i]-'a'] == false) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, Q;
    cin >> M >> Q;
    vector<vector<bool>> graph(N, vector<bool>(N));

    for (int i = 0; i < N; ++i) {
    	graph[i][i] = true;
    }

    while (M--) {
    	char u, v;
    	cin >> u >> v;
    	graph[u-'a'][v-'a'] = true;
    }

    fwarshall(graph);

    while (Q--) {
    	cout << (query(graph) ? "yes" : "no") << endl;
    }
	return 0;
}