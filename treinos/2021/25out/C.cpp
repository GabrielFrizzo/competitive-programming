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
	cin >> N;
	while (N--) {
		ll inp;
		cin >> inp;
		if (inp % 3 == 0) {
			cout << inp/3 << ' ' << inp/3 << ' '<< inp/3 << endl;
		} else if (inp % 4 == 0) {
			cout << inp/4 << ' ' << inp/4 << ' '<< inp/2 << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}