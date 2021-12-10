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

bool isLow(int i, int j) {
	for (pii dir : directions) {
		int ii = i + dir.first;
		int jj = j + dir.second;
		if (valid(ii, jj)) {
			if (m[ii][jj] <= m[i][j]) return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
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

	int total = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if (isLow(i, j)) {
				total += m[i][j] + 1;
			}
		}
	}

	cout << total << endl;

	return 0;
}