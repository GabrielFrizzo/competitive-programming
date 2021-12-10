#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 212345;
const int MOD = 1e9 + 7;

bool b[MxN]; 

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N >> X;

	for (int i = 0; i < N; ++i) {
		int S, D;
		cin >> S >> D;

		for (int j = S; j <= S+D; j++) {
			b[j] = true;
		}
	}

	ll C = MxN;
	int best = -1;
	for (int i = 0; i <= 480; ++i)
	{
		ll total = 0;
		for (int j = i; j < MxN; j += X)
		{
			total += b[j];
		}
		// cout << total << ' ' << i << endl;
		if (total < C) {
			C = total;
			best = i;
		}
	}

	cout << best << ' ' << C << endl;
	return 0;
}