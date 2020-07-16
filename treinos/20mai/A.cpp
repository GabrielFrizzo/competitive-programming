#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

ll solvemin(int K) {
	if (K == 0) return 0;
	return (45*pow(10,K-2)+10*solvemin(K-2));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;

	ll res = K&1 ? 10 : 1;
	K -= K&1;

	if (K <= 0) {
		cout << 0 << endl;
	} else if (K == 2) {
		cout << res*36 << endl;
	} else {
		res *= 36*pow(10,K-2) + 9*solvemin(K-2);
		cout << res << endl;
	}

	return 0;
}
