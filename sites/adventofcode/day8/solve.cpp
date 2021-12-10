#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

/*
	2 -> [1]
	3 -> [7]
	4 -> [4]
	5 -> [2,3,5]
	6 -> [0,6,9]
	7 -> [8]
*/

int solve() {
	string inp[10];
	char pipe;
	for(int i = 0; i < 10; ++i) {
		cin >> inp[i];
	}
	cin >> pipe;



	int total = 0;
	for(int i = 0; i < 4; ++i) {
		string out;
		cin >> out;
		int sz = out.size();
		// cout << sz << endl;
		total += (sz >=2 && sz <= 4) || sz == 7;
	}

	return total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int total = 0;
	while (N--) {
		total += solve();
	}

	cout << total << endl;

	return 0;
}