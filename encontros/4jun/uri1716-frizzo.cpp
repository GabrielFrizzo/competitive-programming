#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

ll div(ll n) {
	for (int i = 2;; ++i) {
		if (n%i == 0) return i;
	}
	assert(false);
}

void euler(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1;
		y = 0;
		return;
	}

	ll x1, y1;
	euler(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1*(a/b);
}

ll expbin(ll a, ll p, ll m) {
	assert(p >= 0);
	if (!p) return 1;
	if (p&1) return a*expbin(a, p-1, m) % m;
	ll res = expbin(a, p/2, m);
	return (res*res) % m;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, e, c;
    cin >> n >> e >> c;
    ll p, q, phi, d;

    p = div(n); q = n/p; phi = (p-1)*(q-1);

    ll y;
    euler(phi, e, y, d);
    d = (d+phi)%phi;
    cout << expbin(c, d, n) << endl;

	return 0;
}
