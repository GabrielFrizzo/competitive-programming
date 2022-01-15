#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;
		long long res = 1;
		if (a == b && a == 0) {
			cout << 0 << endl;
		} else {
			res = pow(26, a)*pow(10,b);
			cout << res << endl;
		}
	}
	return 0;
}