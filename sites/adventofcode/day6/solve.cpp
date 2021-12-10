#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

ll cnt[9];

void simulate() {
	ll zero = cnt[0];
	for(int i = 1; i <= 8; ++i) {
		cnt[i-1] = cnt[i];
	}

	cnt[6] += zero;
	cnt[8] = zero;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(cnt, 0, sizeof cnt);

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		int inp;
		cin >> inp;
		cnt[inp]++;
	}

	for(int day = 0; day <= 256; ++day) {
		simulate();
	}

	ll total = 0;
	for(int i = 0; i < 8; ++i) {
		total += cnt[i];
	}

	cout << total << endl;

	return 0;
}