#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MxN = 1123456;

double memo[MxN];

double f(int n) {
	if (n <= 0) return 0;
	else return memo[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double N, A, B;
	cin >> N >> A >> B;
	double M = B-A+1;
	double rolling = 0;

	if (A == 0) {
		memo[0] = 0;
		for (int i = 1; i < A; ++i) {
			memo[i] = 1;
		}

		for (int i = A-1; i > A-M; --i) {
			rolling += f(i);
		}

		for (int i = A; i <= N; ++i) {
			// debug() << imie(rolling);
			memo[i] = (1/(1-1/M))*(rolling/M+1);
			rolling -= f(i-B);
			rolling += f(i-A);
		}

		cout << fixed << setprecision(6) << memo[(int)N] << endl;
	} else {
		memo[0] = 0;
		for (int i = 1; i < A; ++i) {
			memo[i] = 1;
		}

		for (int i = A-1; i > A-M; --i) {
			rolling += f(i);
		}

		for (int i = A; i <= N; ++i) {
			// debug() << imie(rolling);
			memo[i] = rolling/M+1;
			rolling -= f(i-B);
			rolling += f(i-A+1);
		}

		cout << fixed << setprecision(6) << memo[(int)N] << endl;
	}
}