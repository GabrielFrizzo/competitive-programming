#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MOD = 1e9 + 7;

int m[MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int inp, N = 0;
	while (cin >> inp) {
		m[N++] = inp;
	}

	int total = 0;
	for(int i = 3; i < N; ++i) {
		total += m[i] > m[i-3];
	}

	cout << total << endl;

	return 0;
}