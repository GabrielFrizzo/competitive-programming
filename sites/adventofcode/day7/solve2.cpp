#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

int sumPA(int n) {
	return n*(n+1)/2;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vi v(N);
	for(int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	int best = MOD;
	for(int mean = 0; mean < 1500; ++mean) {
		int total = 0;
		for(int i : v) {
			total += sumPA(abs(mean-i));
		}

		cout << mean << ' ' << total << endl;
		best = min(total, best);
	}

	cout << best << endl;

	return 0;
}