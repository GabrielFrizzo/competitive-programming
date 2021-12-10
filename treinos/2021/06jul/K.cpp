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

	ll n, a, b;

	cin >> n >> a >> b;


	ll best = 3*n;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (!i && !j) continue;
			if ((i*a + j*b) % n == 0 && i + j < best) {
				best = i + j;
			}
		}
	}

	cout << best << endl;

	return 0;
}