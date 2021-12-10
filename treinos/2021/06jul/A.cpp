#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<ll> inp;

	for (int i = 0; i < 6; ++i) {
		ll a;
		cin >> a;
		inp.push_back(a);
	}

	sort(inp.begin(), inp.end());

	ll diff = min(inp[1] - inp[0], inp[2] - inp[1]);
	ll res = -1;
	for (int i = 1; i < 6; ++i) {
		if (inp[i] - inp[i-1] != diff) {
			res = inp[i-1] + diff;
		}
	}


	if (res == -1) {
		if (inp[0] - diff > 0 && diff != 0)
			cout << inp[0] - diff << endl;
		cout << inp[5] + diff << endl; 
	} else {
		cout << res << endl;
	}
	return 0;
}