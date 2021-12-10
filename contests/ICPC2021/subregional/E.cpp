#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

ll num[MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int B, L;
	cin >> B >> L;

	ll total = 0;

	for (int i = 0; i < l; ++i) {
		cin >> num[i]
		total += num[i];
	}

	if (num[i] % N == 0) {
		cout << "0 0\n";
	}

	ll toremove = num[i] % N;

	for (int i = 0; i < L; ++i)
	{
		if (num[i] >= toremove) {
			cout << i << ' ' << toremove << endl;
			return 0;
		}
	}

	cout << "-1 -1\n";

	return 0;
}