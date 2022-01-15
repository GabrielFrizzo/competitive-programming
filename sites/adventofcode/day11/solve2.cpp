#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

const int N = 10;
int m[N][N];

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < N;
}

bool step() {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			m[i][j]++;
		}
	}

	bool flashed[N][N];
	memset(flashed, 0, sizeof flashed);
	int total = 0;
	bool modified = true;
	while(modified) {
		modified = false;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if (m[i][j] > 9) {
					for(int ii = i-1; ii <= i+1; ++ii) {
						for(int jj = j-1; jj <= j+1; ++jj) {
							if ((ii != i || jj != j) && valid(ii, jj) && !flashed[ii][jj]) {
								m[ii][jj]++;
							}
						}
					}
					total++;
					modified = true;
					flashed[i][j] = true;
					m[i][j] = 0;
				}
			}
		}
	}

	return total == N*N;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			char inp;
			cin >> inp;
			m[i][j] = (int) (inp-'0');
		}
	}

	bool done = false;
	int i = 0;
	while(!done) {
		done = step();
		i++;
		// for(int ii = 0; ii < N; ++ii) {
		// 	for(int jj = 0; jj < N; ++jj) {
		// 		cout << m[ii][jj];
		// 	}
		// 	cout << endl;
		// }
	}
	cout << i << endl;

	return 0;
}