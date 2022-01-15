#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	while (cin >> N, N) {
		int res = 0;
		for (int i = 1; i <= N; ++i) {
			res += (N-i+1)*(N-i+1);
		}

		cout << res << endl;
	}


	return 0;
}
