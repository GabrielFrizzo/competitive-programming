#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MOD = 1e9 + 7;

vi tree[MxN];
vi deaths;
bool dead[MxN];
int current_death = 0, total_people, total_deaths = 0;

void dfs(int u) {
	if (current_death == total_deaths) return;
	if (!dead[u]) {
		for (; current_death < total_deaths; current_death++) {
			dead[deaths[current_death]] = true;
			if (dead[u]) break;
			cout << u << endl;
		}
	}

	for(int v : tree[u]) {
		dfs(v);
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int Q;
	int current = 1;
	cin >> Q;

	while (Q--) {
		int inp;
		cin >> inp;
		if (inp == 2) {
			cin >> inp;
			deaths.push_back(inp);
			total_deaths++;
		} else {
			cin >> inp;
			tree[inp].push_back(++current);
		}
	}
	total_people = current-1;

	dfs(1);

	return 0;
}