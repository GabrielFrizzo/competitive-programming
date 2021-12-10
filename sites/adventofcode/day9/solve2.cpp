#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;
int N, M;
int m[MxN][MxN];
vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

bool visited[MxN][MxN];
int dfs(int i, int j) {
	// cout << i << ' ' << j << ' ' << m[i][j] << ' ' << visited[i][j] << endl;
	if (visited[i][j] || m[i][j] == 9) return 0;
	visited[i][j] = true;

	int total = 1;
	for(pii dir : directions) {
		int ii = i + dir.first;
		int jj = j + dir.second;
		if (valid(ii, jj)) {
			// cout << i << ',' << j << "->" << ii << ',' << jj << endl;
			total += dfs(ii, jj);
		}
	}

	return total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			char inp;
			cin >> inp;
			m[i][j] = (int) (inp - '0');
			// cout << m[i][j] << ' ';
		}
		// cout << endl;
	}
	// cout << endl;

	vi sizes;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			sizes.push_back(dfs(i, j));
			// cout << *(--sizes.end()) << endl;
		}
	}
	sort(sizes.rbegin(), sizes.rend());
	for(int i : sizes) {
		// cout << i << endl;
	}
	int total = 1;
	for(int i = 0; i < 3; ++i) {
		total *= sizes[i];
	}

	cout << total << endl;

	return 0;
}