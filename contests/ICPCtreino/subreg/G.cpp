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
	int total = 100, best = total;
	while (N--) {
		int inp;
		cin >> inp;
		total += inp;
		best = max(best, total);
	}

	cout << best << endl;

	return 0;
}