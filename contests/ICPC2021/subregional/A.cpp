#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

ll m[MxN];
ll memo[MxN][]


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, R;
	cin >> N >> R;

	for(int i = 0; i < N; ++i) {
		cin >> m[i];
	}

	ll total = 0;
	for (int i = N-1; i >= 0; --i) {
		total += R-m[i]+1;		
	}

	return 0;
}