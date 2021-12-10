#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 11234;
const int MOD = 1e9 + 7;

int called[MxN], boards[MxN][5][5];
bool done[MxN][5][5];
int N = 0, M = 0;

void testh(int b, int row, int n) {
	for(int j = 0; j < 5; ++j) {
		if (!done[b][row][j]) return;
	}
	int total = 0;
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < 5; ++j) {
			if (!done[b][i][j] && boards[b][i][j] != n) total += boards[b][i][j];
			// cout << boards[b][i][j] << ' ';
		}
		// cout << endl;
	}

	cout << n << ' ' << total << ' ' << n*total << endl;
}

void testv(int b, int col, int n) {
	for(int i = 0; i < 5; ++i) {
		if (!done[b][i][col]) return;
	}
	int total = 0;
	cout << endl;
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < 5; ++j) {
			if (!done[b][i][j] && boards[b][i][j] != n) total += boards[b][i][j];
			// if (done[b][i][j]) cout << "\033[1;31m";
			// cout << boards[b][i][j] << ' ';
			// cout << "\033[0m";
		}
		// cout << endl;
	}

	cout << n << ' ' << total << ' ' << n*total << endl;
}

void simulate(int n) {
	for(int b = 0; b < M; ++b) {
		for(int i = 0; i < 5; ++i) {
			for(int j = 0; j < 5; ++j) {
				if (boards[b][i][j] == n) {
					done[b][i][j] = true;
					testh(b, i, n);
					testv(b, j, n);
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c;
	memset(done, 0, sizeof done);
	do {
		cin >> called[N++];
		cin >> c;
	} while (c == ',');
	

	while (cin >> boards[M][0][0]) {
		for(int i = 0; i < 5; ++i) {
			for(int j = 0; j < 5; ++j) {
				if (i || j)
					cin >> boards[M][i][j];
			}
		}
		M++;
	}

	for(int i = 0; i < N; ++i) {
		simulate(called[i]);
	}

	return 0;
}