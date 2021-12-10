#include <bits/stdc++.h>
using namespace std;

const int MxN = 1123;

bool m[MxN][MxN];
int N = 0, M;

int get(int j) {
	int ret = 0;
	for(int i = 0; i < M; ++i) {
		ret |= m[j][i] << (M-i-1);
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	string inp;
	while (cin >> inp) {
		M = inp.size();
		for(int i = 0; i < M; ++i) {
			m[N][i] = inp[i] == '1';
		}
		N++;
	}

	int ans1 = 0, ans2 = 0;

	bool excluded[MxN];
	memset(excluded, 0, sizeof excluded);
	for(int j = 0; j < M; ++j) {
		int cnt = 0, total = 0;
		for(int i = 0; i < N; ++i) {
			if (excluded[i]) continue;
			cnt += m[i][j];
			total++;
		}

		bool toKeep = cnt >= (total+1)/2;

		for(int i = 0; i < N; ++i) {
			excluded[i] |= m[i][j] != toKeep;
		}
	}

	for(int i = 0; i < N; ++i) {
		if (!excluded[i]) ans1 = get(i);
	}
	
	memset(excluded, 0, sizeof excluded);
	for(int j = 0; j < M; ++j) {
		int cnt = 0, total = 0;
		for(int i = 0; i < N; ++i) {
			if (excluded[i]) continue;
			cnt += m[i][j];
			total++;
		}

		bool toKeep = cnt < (total+1)/2;

		for(int i = 0; i < N; ++i) {
			excluded[i] |= m[i][j] != toKeep;
			if (!excluded[i]) ans2 = get(i);
		}
	}

	cout << ans1 << ' ' << ans2 << endl;
	cout << ans1 * ans2 << endl;
	return 0;
}