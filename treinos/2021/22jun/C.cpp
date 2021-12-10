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

	string N;
	cin >> N;

	ll cum = 0;
	for (char c : N) {
		cum += (c - '0');
	}

	cout << (((cum) % 3) + 3) % 3 << endl;

	return 0;
}