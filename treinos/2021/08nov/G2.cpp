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

void tentativa(ll n, ll nxt) {
	int i;
	string answer = "";
	for(i = nxt; i > 2; --i) {
		if (n == 1) {
			cout << answer << endl;
			exit(0);
		}
		if (n%fib[i] == 0) {
			n /= fib[i];
			answer += repeat(i);
			i++;
		}
	}
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


	for(int i = MxN-1; i >= 2; --i) {
		tentativa(n, i);
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}