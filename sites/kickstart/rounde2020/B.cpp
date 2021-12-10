#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
	int N, A, B, C;
	cin >> N >> A >> B >> C;

	if (A + B - C > N) {
		cout << "IMPOSSIBLE\n";
	} else if (A == B && B == C) {
		if (N != 1 && A == 1) {
		cout << "IMPOSSIBLE\n";
		} else {
			for (int i = 1; i < A; ++i) {
				cout << N << ' ';
			}
			for (int i = 0; i < N - A; ++i) {
				cout << 1 << ' ';
			}
			cout << N;
			cout << endl;
		}
	} else if (A + B - C == N){
		for (int i = 1; i <= A - C; ++i) {
			cout << i << ' ';
		}
		for (int i = 0; i < C; ++i) {
			cout << N << ' ';
		}
		for (int i = 0, j = N-1; i < B - C; ++i) {
			cout << j-- << ' ';
		}
		cout << endl;
	} else {
		int res = N - (A+B-C);
		int i;
		bool kkk = false;
		for (i = 2; i <= A - C + 1; ++i) {
			cout << i << ' ';
			kkk = true;
		}
		if (kkk) {
			for (int p = 0; p < res; ++p) {
				cout << 1 << ' ';
			}
		}
		for (int j = 0; j < C; j++) {
			cout << N << ' ';
		}
		if (!kkk) {
			for (int p = 0; p < res; ++p) {
				cout << 1 << ' ';
			}
		}
		for (int j = 0, k = N; j < B - C; ++j) {
			cout << --k << ' ';
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}