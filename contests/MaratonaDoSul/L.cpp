#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	double a, b;
	cin >> N >> a >> b;
	int aint, bint;
	aint = (int) (a*10); // 1.8
	bint = (int) (b*10);
	int total = aint/bint - !(bool)(aint%bint); // 2 2.0 0.9 Alice Bob
	int rest = aint % bint;
	if (!rest) {
		rest = bint;
	}

	int rounds = total % N;
	// cout << total << ' ' << rest << ' ' << rounds << endl;
	string names[100];
	for (int i = 0; i < N; ++i) {
		cin >> names[i];
	}
	cout << names[rounds] << ' ' << fixed << setprecision(1) << rest/10. << endl;

	return 0;
}