#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxM = 212;
const int MxC = 21;
const int MxK = 21;
const int MOD = 1e9 + 7;

int prices[MxC][MxK];
bool memo[2][MxM];

void solve() {
	memset(prices, -1, sizeof(prices));
	memset(memo, false, sizeof(memo));
	int M, C;
	cin >> M >> C;
	for (int i = 0; i < C; ++i) {
		int K;
		cin >> K;
		for (int j = 0; j < K; ++j) {
			cin >> prices[i][j];
		}
	}

	for (int i = 0; prices[0][i] != -1; ++i) {
		if (prices[0][i] <= M)
			memo[0][M-prices[0][i]] = true;
	}

	for (int i = 1; i < C; ++i) {
		for (int j = 0; j <= M; ++j) {
			memo[i%2][j] = 0;
			for (int k = 0; prices[i][k] != -1; ++k) {
				memo[i%2][j] |= memo[(i-1)%2][j+prices[i][k]];
			}
		}
	}


	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cerr << memo[i][j] << ' ';
		}
		cerr << endl;
	}
	cerr << endl;
	for (int i = 0; i <= M; ++i) {
		if (memo[(C-1)%2][i]) {
			cout << M-i << endl;
			return;
		}
	}
	cout << "no solution" << endl;
}


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--) {
		solve();
	}

	return 0;
}