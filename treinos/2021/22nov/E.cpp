#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MOD = 1e9 + 7;

int arrived[MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	memset(arrived, -1, sizeof arrived);

	for(int i = 0; i < N; ++i) {
		int t, d;
		cin >> t >> d;
		arrived[t] = d;
	}

	int people = 0;
	int i;
	for(i = 0; people < N; ++i) {
		if (arrived[i] == 0) {
			people++;
		} else if (arrived[i] == 1) {
			people++;
		}
	}

	cout << total << endl;

	return 0;
}