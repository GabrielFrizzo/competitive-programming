#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 1123;
const int INF = 1e9+5;

int g[MxN][MxN];
int N, M;

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

void solve() {
	cin >> N >> M;
	pii init, end;
	vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	queue<piii> fires;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char inp;
			cin >> inp;
			if (inp == 'S') init = {i, j};
			if (inp == 'E') end = {i, j};

			if (inp == '#') g[i][j] = 0;
			else if (inp == 'F') {
				fires.push({{i, j}, 0});
				g[i][j] = INF;
			} else {
				g[i][j] = INF;
			}
		}
	}

	while (!fires.empty()) {
		int cr, cc;
		piii curr = fires.front(); fires.pop();
		tie(cr, cc) = curr.first;
		if (g[cr][cc] != INF) continue;
		g[cr][cc] = curr.second;

		for (pii d : directions) {
			int nr = cr+d.first, nc = cc+d.second;
			// cout << nr << " " << nc << endl;
			if (valid(nr, nc) && g[nr][nc] == INF) {
				fires.push({{nr, nc}, curr.second+1});
			}
		}
	}

	// for (int i = 0; i < N; ++i) {
	// 	for (int j = 0; j < M; ++j) {
	// 		cout << g[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	queue<piii> q; q.push({init, 0});
	while (!q.empty()) {
		int cr, cc;
		piii curr = q.front(); q.pop();
		tie(cr, cc) = curr.first;
		if (g[cr][cc] <= curr.second) continue;
		if (cr == end.first && cc == end.second) {
			cout << "Y" << endl;
			return;
		}
		g[cr][cc] = 0;

		for (pii d : directions) {
			int nr = cr+d.first, nc = cc+d.second;
			if (valid(nr, nc) && g[nr][nc] > curr.second+1) {
				q.push({{nr, nc}, curr.second+1});
			}
		}
	}

	cout << "N" << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
    	solve();
    }
	return 0;
}