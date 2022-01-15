#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
using piii = pair<pii, pii>;

const int MxN = 512;
const int MOD = 1e9 + 7;
const ll INF = 1e18+7;

ll m[MxN][MxN];
ll visited[MxN][MxN];
ll dist[MxN][MxN];
int N, M;

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

ll dij() {
	priority_queue<piii, vector<piii>, greater<piii>> q;
	q.push({{0, 0}, {0, 0}});
	dist[0][0] = 0;

	while(!q.empty()) {
		int i = q.top().second.first;
		int j = q.top().second.second;
		int curr = q.top().first.first;
		q.pop();
		if (visited[i][j]) continue;
		visited[i][j] = true;
		// cout << i << ' ' << j << ' ' << curr << endl;
		if (i == N-1 && j == M-1) return curr;

		for (pii dir : directions) {
			int ii = i + dir.first;
			int jj = j + dir.second;
			if (valid(ii, jj) && !visited[ii][jj] && curr + m[ii][jj] < dist[ii][jj]) {
				dist[ii][jj] = curr + m[ii][jj];
				q.push({{dist[ii][jj], -(ii*ii+jj*jj)}, {ii, jj}});
			}
		}
	}
	return INF;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i = 0; i < 5*N; ++i) {
		for(int j = 0; j < 5*M; ++j) {
			dist[i][j] = INF;
			visited[i][j] = false;
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			char inp;
			cin >> inp;
			m[i][j] = inp-'0';
		}
	}
	int NN = N, MM = M;
	N *= 5;
	M *= 5;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			m[i][j] = (m[i%NN][j%MM] + i/NN + j/MM - 1) % 9 + 1;
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cout << m[i][j];
		}
		cout << endl;
	}

	cout << dij() << endl;


	return 0;
}