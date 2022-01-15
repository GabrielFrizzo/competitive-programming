#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	while (cin >> N, N) {
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			int inp;
			cin >> inp;
			ans ^= inp;
		}

		cout <<  (ans == 0 ? "No" : "Yes") << endl;
	}


	return 0;
}