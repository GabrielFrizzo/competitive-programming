#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 93;
const int MOD = 1e9 + 7;

ll fib[MxN];

string repeat(int a) {
	a-=2;
	string ret = "";
	while (a--) ret += 'A';
	return ret + 'B';
}

string solve(ll n, ll nxt) {
	if (n == 1) {
		return "";
	}
	for(int i = nxt; i > 2; --i) {
		if (n%fib[i] == 0) {
			string answer = solve(n/fib[i], i);
			if (answer != "IMPOSSIBLE") {
				return repeat(i) + answer;
			}
		}
	}
	return "IMPOSSIBLE";
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;

	fib[1] = fib[2] = 1;
	for(int i = 2; i < MxN; ++i) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	cout << solve(n, MxN-1) << endl;

	return 0;
}