#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int d1i[] = {1, -1, 1, -1};
int d1j[] = {1, -1, -1, 1};
int d2i[] = {2, -2, 2, -2};
int d2j[] = {2, -2, -2, 2};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < 10 && j < 10;
}

int test(int i, int j, vector<vector<char>> m) {
	m[i][j] = '#';
	// for (int ii = 0; ii < 10; ++ii) {
	// 	for (int jj = 0; jj < 10; ++jj)
	// 		cout << m[ii][jj];
	// 	cout << endl;
	// }
	// cout << endl;
	int best = 0;
	for (int d = 0; d < 4; ++d) {
		int n2i = i+d2i[d], n2j = j+d2j[d];
		if (!valid(n2i, n2j)) continue;
		int ni = i+d1i[d], nj = j+d1j[d];
		if (m[ni][nj] == 'B' && m[n2i][n2j] == '#') {
			vector<vector<char>> mcpy = m;
			mcpy[ni][nj] = '#';
			best = max(best, test(n2i, n2j, mcpy)+1);
		}
	}

	return best;
}

void solve() {
	vector<vector<char>> m(10, vector<char>(10));

  for (int i = 0; i < 10; ++i) {
  	for (int j = 0; j < 10; ++j) {
  		scanf(" %c", &m[i][j]);
  	}
  }

 //  for (int ii = 0; ii < 10; ++ii) {
	// 	for (int jj = 0; jj < 10; ++jj)
	// 		cout << m[ii][jj];
	// 	cout << endl;
	// }

  int best = 0;

	for (int i = 0; i < 10; ++i) {
  	for (int j = 0; j < 10; ++j) {
  		if (m[i][j] == 'W') best = max(test(i, j, m), best);
  	}
  }

  cout << best << endl;
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