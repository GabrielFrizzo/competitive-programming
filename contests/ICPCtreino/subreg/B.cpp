#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

bool m[10][10];

void no() {
	cout << "N\n";
	exit(0);
}

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < 10 && j < 10;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while (N--) {
		int d, l, r, c;
		cin >> d >> l >> r >> c;
		r--;c--;
		if (d) {
			for (int i = r; i < r+l; ++i)
			{
				// cout << valid(i, c) << i << c << endl;
				if (!valid(i, c) || m[i][c]) no();
				m[i][c] = true;
			}
		} else {
			for (int i = c; i < c+l; ++i) {
				// cout << valid(r, i) << r << i << endl;
				if (!valid(r, i) || m[r][i]) no();
				m[r][i] = true;
			}
		}
	}
	cout << "Y\n";

	return 0;
}