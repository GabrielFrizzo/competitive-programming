#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	while (cin >> N, N) {
		int i;
		for (i = 1; i <= N; i<<=1) {}
		cout << (N - (i>>1) == 0 ? N : (N - (i>>1))*2) << endl;
	}


	return 0;
}
