#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxS = 1e6;
const int MxN = 15;

int N;
char m[MxN][MxN];
int nmemo[MxN], memo[MxN][MxS][MxN], sol[MxN];

int feasible(int c, int p) {
	for (int i = 0; i < p; ++i) {
		if (sol[i] == c || p-i == abs(c- sol[i]))
			return 0;
	}
	return 1;
}

void backtrack(int p, int n) {
	if (p==n+1) {
		for (int i = 0; i <= n; ++i)
			memo[n][nmemo[n]][i] = sol[i];
		nmemo[n]++;
		return;
	}
	for (int c = 0; c <= n; ++c) {
		if (feasible(c, p)) {
			sol[p] = c;
			backtrack(p+1, n);
		}
	}
}

void solve() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> m[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < nmemo[N-1]; ++i) {
		for (int j = 0; j < N; ++j) {
			if (m[memo[N-1][i][j]][j] == '*') {
				ans--;
				break;
			}
		}
		ans++;
	}

	cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < MxN; ++i) {
    	nmemo[i] = 0;
    	backtrack(0, i);
    	cout << i+1 << ' ' << nmemo[i] << endl;
    }

    int cas = 1;
    while(cin >> N, N) {
    	cout << "Case " << cas++ << ": ";
    	solve();
    	cout << endl;
    }
	return 0;
}
