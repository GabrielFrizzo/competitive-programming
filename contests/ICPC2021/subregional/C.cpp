#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 212345;
const int MOD = 1e9 + 7;

ll num[MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int B, L;
	cin >> B >> L;

	ll total = 0;

	for (int i = 0; i < L; ++i) {
		cin >> num[i];
		total += i%2 ? -num[i] : num[i];
	}

	// cerr << total << endl;
	if (total % (B+1) == 0) {
		cout << "0 0\n";
		return 0;
	}
	ll N = B+1;
	ll toremove = ((total%N)+N) % N;

	for (int i = 0; i < L; ++i) {
		if (i % 2) {
			int toadd = N-toremove;
			if (num[i] >= toadd) {
				cout << i+1 << ' ' << (num[i]-toadd) << endl;
				return 0;
			}
		} else {
			if (num[i] >= toremove) {
				cout << i+1 << ' ' << num[i]-toremove << endl;
				return 0;
			}
		}
	}

	cout << "-1 -1\n";

	return 0;
}