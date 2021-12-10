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

	vi v;
	int T, D, M;
	cin >> T >> D >> M;

	v.push_back(0);
	for (int i = 0; i < M; ++i)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	v.push_back(D);

	for(int i = 0; i <= M; ++i) {
		if (v[i+1]-v[i] >= T) {
			cout << "Y\n";
			return 0;
		}
	}
	cout << "N\n";

	return 0;
}