#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 812345;
const ll MOD = 1e9+7;

// abcde
// 2 2
// 3 4 3
// 4 6 6 4
// 5 8 9 (N - i * i+1)

void solve() {
	ll N;
	string s;
	cin >> N >> s;
	char last = 0;
	ll lastp = -1;
	ll count = 0;

	for (ll i=1; i <= N; ++i) {
		char c = s[i-1];
		if (c == 'X' || c == 'O') {
			if (last != 0 && c != last) {
				count += (N-i+1LL) * lastp;
				count %= MOD;
			}
			last = c;
			lastp = i;
		}
	}

	cout << count;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}