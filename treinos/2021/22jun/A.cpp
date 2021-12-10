#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;


ll power(ll i) {
	ll ret = 2050;
	while (ret * 10 <= i) {
		ret *= 10;
	}

	return ret;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll N, i;
	cin >> N;
	while (N--) {
		cin >> i;
		if (i % 2050) {
			cout << -1 << endl;
		} else {
			ll j = 0;
			while (i) {
				ll p = power(i);
				j += i / p;
				i %= p;
			}

			cout << j << endl;
		}
	}

	return 0;
}