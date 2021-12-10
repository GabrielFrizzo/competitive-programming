#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MOD = 1e9 + 7;

ll a[MxN], b[MxN];
ll N, K;

ll calc(ll m) {
	ll total = 0;
	for (int i = 0; i < N; ++i) {
		if (m >= a[i]) {
			total += (m-a[i])/b[i] + 1LL;
			if (total > K) return total;
		}
	}
	return total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i] >> b[i];
	}

	ll inf = 1, sup = 2123456789012345678LL, m;
	while (sup > inf){
		m = inf + (sup-inf)/2LL;
		
		ll total = calc(m);
		// cout << m << ' ' << total << endl;
		if (total < K) inf = m+1LL;
		else sup = m;
	}
	
	// cout << calc(m+1) << endl;
	cout << (calc(m) < K ? m+1LL : m) << endl;

	return 0;
}