#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MxT = 51;
const int MOD = 1e9 + 7;

ll memo[MxN][MxT];
int T, M, N;

ll dp(ll i, int t) {
	if (i < M || i > N) return 0;
	if (t == 1) return 1;
	if (memo[i][t] != -1) return memo[i][t];
	return memo[i][t] = (((dp(i-1, t-1) + dp(i+1, t-1)) % MOD) + MOD) % MOD;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T >> M >> N;
	memset(memo, -1, sizeof(memo));
	ll total = 0;
	for (int i = M; i <= N; ++i) {
		total += dp(i, T);
		total = ((total % MOD) + MOD) % MOD;
	}

	cout << total << endl;

	return 0;
}