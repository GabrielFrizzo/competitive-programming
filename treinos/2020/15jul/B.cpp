#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using piiii = pair<pii, pii>;
const int MxN = 100;

int N, M;
char m[MxN][MxN];
bool vis[MxN][MxN][10];
int total_end;

vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
vector<pii> directions2 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M && m[i][j] != '#';
}

int bfs(int i, int j) {
	queue<piiii> q; q.push({{i, j}, {0, 0}});
	vis[i][j][0] = true;
	while(!q.empty()) {
		int curri, currj, cost, done;
		tie(curri, currj) = q.front().first;
		tie(cost, done) = q.front().second;
		q.pop();

		for (pii d : directions2) {
			int ni = curri + d.first, nj = currj + d.second;
			if (vis[ni][nj][done] == true || !valid(ni, nj)) continue;

			vis[ni][nj][done]=true;

			if (m[ni][nj] == '.') {
				q.push({{ni, nj}, {cost+1, done}});
			}
			else if (m[ni][nj] == '!') {
				if (done == total_end-1) return cost;
				else {
					q.push({{ni, nj}, {cost+1, done+1}});
					vis[ni][nj][done+1] = true;
				}
			} 
		}
	}
	return -1;
}

void solve() {
	pii pos;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> m[i][j];
			if (m[i][j] == '~') m[i][j] = '#';
			else if (m[i][j] == '@') pos = {i,j};
			else if (m[i][j] == '!') total_end++;
		}
	}


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (m[i][j] == '*') {
				m[i][j] = '#';
				for (pii d : directions) {
					int ni = i + d.first, nj = j + d.second;
					if (valid(ni, nj)) m[ni][nj] = '#';

				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << m[i][j];
		cout << endl;
	}


	cout << (bfs(pos.first, pos.second) +1)*2<< endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> N >> M, N) {
		solve();
	}


	return 0;
}
