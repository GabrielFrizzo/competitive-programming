#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
	ll a, b;
	cin >> a >> b;

	if (b > a) {
		ll aux = b;
		b = a;
		a = aux;
	}

	if (a % b) {
		cout << -1 << endl;
		return;
	}

	ll res = a/b;

	ll l = res&-res;

	if (l != res) {
		cout << -1 << endl;
		return;
	}

	int ans = 0;

	while (l % 8 == 0) {
		l /= 8;
		ans++;
	}

	while (l % 4 == 0) {
		ans++;
		l /= 4;
	}

	while (l % 2 == 0) {
		ans++;
		l /= 2;
	}

	cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC;
    cin >> TC;
    while(TC--) {
    	solve();
    }
	return 0;
}