#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const int MxN = 5123;
const ll MOD = 1e9 + 7;

int memo[MxN][MxN];

ll iter(int S, int B) {
	if (B < 0 || S < 0) return 0;
	if (B == 0) return 1;
	if (S == 0) return 0;
	if (memo[S][B] != -1) return memo[S][B];

	ll total = iter(S, B-S);
	total %= MOD;
	total += 2*(iter(S-1, B) % MOD);
	total %= MOD;
	total -= iter(S-2, B);
	total = (total + MOD) % MOD;

	// cout << S << ' ' << B << endl;
	// cout << total << endl;
	// if (total < 0) exit(0);
	return memo[S][B] = total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int S, B;
	cin >> S >> B;
	B -= S;
	memset(memo, -1, sizeof(memo));
	// iter(S, B);
	// for (int i = 1; i <= S; ++i) {
	// 	for (int j = 1; j <= B; ++j) {
	// 		cout << memo[i][j] << '\t';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	cout << iter(S, B) << endl;

	return 0;
}