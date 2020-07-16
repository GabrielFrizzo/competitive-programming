#include <bits/stdc++.h>
using namespace std;

#define MxN 1123
using pii = pair<int,int>;
using piii = pair<int,pii>;
using vi = vector<int>;

int m[MxN][MxN], visited[MxN][MxN];

void solve() {
	int N,M;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> m[i][j];

	priority_queue<piii, vector<piii>, greater<piii>> pq;
	memset(visited, 0, sizeof(visited));
	pq.push({m[0][0], {0,0}});
	auto valid = [&](int i, int j) {return i >= 0 && j >= 0 && i < N && j < M;};
	vector<pii> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
	while (!pq.empty()) {
		piii curr = pq.top(); pq.pop();
		int i = curr.second.first, j = curr.second.second;
		if (i == N-1 && j == M-1) { cout << curr.first << endl; return; }
		if (visited[i][j]) continue;
		visited[i][j] = 1;
		for (pii d : dirs) {
			piii nxt = {curr.first, {i+d.first, j+d.second}};
			int ni = nxt.second.first, nj = nxt.second.second;
			if (!valid(ni, nj)) continue;
			nxt.first += m[ni][nj];
			pq.push(nxt);
		}
	}
}

int main(int argc, char const *argv[])
{
	int TC;
	scanf("%d", &TC);

	while (TC--) {
		solve();
	}

    
	return 0;
}