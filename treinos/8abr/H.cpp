#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long int d, m;
	cin >> d >> m;

	long long int res = 1, i;
	
	for (i = 1; i<<1 <= d; i<<=1) {
		res *= i + 1;
		res %= m;
	}

	res *= (d % i) + 2;
	// cout << i << " " << res << endl;
	cout << ((res-1)+m) % m << endl;
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