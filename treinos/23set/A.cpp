#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, T;
	cin >> N >> T;

	if (T == 2) {
 		cout << ((N-1)*(N-1)*(N-2))/2 - ((N-2)*(N-1)*(2*N-3))/6 << endl;
	}	else if (T == 1) {
		cout << N * (N-1) << endl;
	} else {
		cout << N << endl;
	}

	return 0;
}

