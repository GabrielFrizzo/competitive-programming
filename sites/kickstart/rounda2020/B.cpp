#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 51;
const int MxK = 31;
const int MxP = MxN*MxK;

int memo[MxN][MxK][MxP];
vector<vi> v;
int N, K, P;

int dp(int n, int k, int p) {
    if (memo[n][k][p] != -1) return memo[n][k][p];

    if (p == 0) return 0;
    if (n >= N) return 0;
    if (k >= K) return memo[n][k][p] = dp(n+1, 0, p);

    return memo[n][k][p] = max(dp(n+1, 0, p), dp(n, k+1, p-1)+v[n][k]);
}

void solve() {
    cin >> N >> K >> P;

    v.assign(N, vi(K));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> v[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, P) << endl;

    // for (int p = 1; p <= P; ++p) {
    //     for (int i = 0; i < N; ++i) {
    //         for (int j = 0; j < K; ++j) {
    //             cout << memo[i][j][p] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	solve();
    }
	return 0;
}