#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int fac(int n) {
	if (n == 1) return 1;
	return fac(n-1);
}

void solve() {
	int g, n;
	cin >> g >> n;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		int inp;
		cin >> inp;
		total += inp;
	}

	double dn = n;
	cout << pow(n, g-total)*fac(g)/pow(n, g) << endl;
}

int main(int argc, char const *argv[])
{
 	ios_base::sync_with_stdio(0);
 	cin.tie(0);

 	int TC;
 	cin >> TC;
 	while (TC--)
 		solve();


	return 0;
}
