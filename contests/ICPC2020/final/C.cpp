#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MOD = 1e9 + 7;

ll tabless[MxN];
int N, avg;

ll _left() {
	ll tables[MxN]; memcpy(tables, tabless, sizeof(tabless));
	ll total = 0;
	ll cum = 0;
	for (int i = 0; i < N; ++i) {
		total += cum;
		if (tables[i] <= 0) {
			int dim = min(cum, abs(tables[i]));
			cum -= dim;
			tables[i] += dim;
		} else {
			cum += tables[i];
		}
	}
	for (int i = 0; i < N; ++i) {
		total += cum;
		if (tables[i] < 0) {
			int dim = min(cum, abs(tables[i]));
			cum -= dim;
			tables[i] += dim;
		}
	}

	// cout << total << endl;
	return total;
}

ll _right() {
	ll tables[MxN]; memcpy(tables, tabless, sizeof(tabless));
	ll total = 0;
	ll cum = 0;
	for (int i = N-1; i >=0; --i) {
		total += cum;
		if (tables[i] <= 0) {
			int dim = min(cum, abs(tables[i]));
			cum -= dim;
			tables[i] += dim;
		} else {
			cum += tables[i];
		}
	}
	for (int i = N-1; i >=0; --i) {
		total += cum;
		if (tables[i] < 0) {
			int dim = min(cum, abs(tables[i]));
			cum -= dim;
			tables[i] += dim;
		}

	}
	// cout << total << endl;
	return total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	avg = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> tabless[i];
		avg += tabless[i];
	}

	avg /= N;

	for (int i = 0; i < N; ++i)
	{
		tabless[i] -= avg;
	}

	cout << min(_left(), _right()) << endl;

	return 0;
}