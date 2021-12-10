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

	vi inp;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		inp.push_back(a);
	}

	int small = inp[0];
	bool flag = false;
	for (int i = 1; i < n; ++i)
	{
		if (inp[i] < inp[i-1]) {
			if (flag) {
				cout << "Lie" << endl;
				exit(0);
			}

			flag = true;
		}

		if (flag && inp[i] > small) {
			if (flag) {
				cout << "Lie" << endl;
				exit(0);
			}
		}
	}

	cout << "Phew" << endl;

	return 0;
}