#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MOD = 1e9 + 7;


int meal[MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, D, M;
	cin >> T >> D >> M;

	for(int i = 1; i <= M; ++i) {
		cin >> meal[i];
	}

	meal[M+1] = D;

	for(int i = 0; i <= M; ++i) {
		if (meal[i+1] - meal[i] >= T) {
			cout << "Y\n";
			return 0;
		}
	}

	cout << "N\n";

	return 0;
}