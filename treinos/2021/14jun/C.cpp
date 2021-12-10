#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<ll,ll>;

const int MxN = 5*112345;
const int MOD = 1e9 + 7;

ll giants[MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, P, Q;
	cin >> N >> P >> Q;

	for (int i = 0; i < N; ++i)
	{
		ll X, Y;
		cin >> X >> Y;

		giants[i] = Y*Q-X*P;
	}

	sort(giants, giants + N);

	for (int i = 0; i < N; ++i)
	{
		if ()
	}

	return 0;
}