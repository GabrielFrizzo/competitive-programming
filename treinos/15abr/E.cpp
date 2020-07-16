// ternary search
#include <bits/stdc++.h>
using namespace std;

#define MxN 11234
typedef long long ll;

ll n, h[MxN], c[MxN];

ll f(ll height) {
	ll total = 0;

	for (int i = 0; i < n; ++i) {
		total += abs(height - h[i])*c[i];
	}
	return total;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> h[i];
	for (int i=0; i<n; ++i)
		cin >> c[i];

	ll inf = 0, sup = MxN;
    while (sup - inf >= 3) {
    	// cout << inf << " " << sup << endl;
      	ll a = inf + (sup - inf) / 3, b = sup - (sup - inf) / 3;
      	ll fa = f(a), fb = f(b);
      	// cout << fa << " " << fb << endl;
      	if (fa < fb) sup = b;
      	else if (fa > fb) inf = a;
      	else { sup = b; inf = a; }
    }
    ll ans = f(inf) < f(sup) ? inf : sup;
    if (sup - inf == 2) ans = f(inf + 1) < f(ans) ? inf + 1 : ans;

    cout << f(ans) << endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    	solve();

   
	return 0;
}
 
