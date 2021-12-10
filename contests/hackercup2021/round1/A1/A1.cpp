#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

void solve() {
	int N;
	string s;
	cin >> N >> s;
	char last = 0;
	int count = 0;
	for (char c : s) {
		if (c != last && (c == 'X' or c == 'O')) {
			count++;
			last = c;
		}
	}

	cout << max(0, count-1);
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