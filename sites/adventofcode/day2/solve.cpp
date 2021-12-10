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

	string s;
	int inp;
	int up = 0, forward = 0;
	while (cin >> s) {
		cin >> inp;

		if (s == "down")
			up -= inp;
		else if (s == "up")
			up += inp;
		else
			forward += inp;

	}

	cout << up * forward << endl;

	return 0;
}