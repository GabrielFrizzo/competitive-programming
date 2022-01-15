#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 10;

int n, m;
int mini[MxN][MxN], maxi[MxN][MxN];

void solve() {
	memset(mini, -1, sizeof(mini));
	for (int i = 0; i < MxN; ++i)
		for (int j = 0; j < MxN; ++j)
			maxi[i][j] = MxN+1000;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		if (c < 0) {
			mini[a][b] = max(-c, mini[a][b]);
		} else {
			maxi[a][b] = min(c, maxi[a][b]);
		}
	}

	vector<int> perm;
	for (int i = 0; i < n; ++i) perm.push_back(i);

	ll ans = 0;
	do {
		bool good = true;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				int posi = perm[i], posj = perm[j];
				// cout << i << ' ' << j << endl;
				if (mini[i][j] > abs(posi-posj) || maxi[i][j] < abs(posi-posj)) {
					// cout << "mini" << (abs(posi-posj)) << endl;
					good = false;
					break;
				}
			}
			if (!good) break;
		}
		if (good)
			ans++;
	} while(next_permutation(perm.begin(), perm.end()));

	cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> m, n) {
    	solve();
    }
	return 0;
}