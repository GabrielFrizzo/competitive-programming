#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112345;

int Q;
char op[MxN];
int v[MxN], x[MxN], ans[MxN];
vi tree[MxN];
deque<int> dq;

void dfs(int u) {
	if (u > Q) return;

	if (op[u] == 'E') {
		dq.push_back(x[u]);
		for (int vv : tree[u]) {
			dfs(vv);
		}
		dq.pop_back();
	} else {
		int val = dq.front();
		ans[u] = val;
		dq.pop_front();
		for (int vv : tree[u]) {
			dfs(vv);
		}
		dq.push_front(val);
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> Q;
    for (int i = 1; i <= Q; ++i) {
    	cin >> op[i] >> v[i];
    	if (op[i] == 'E')
    		cin >> x[i];
    	tree[v[i]].push_back(i);
    }

    for (int u : tree[0])
    	dfs(u);

    for (int i = 1; i <= Q; ++i) {
    	if (op[i] == 'D')
    		cout << ans[i] << endl;
    }
	return 0;
}