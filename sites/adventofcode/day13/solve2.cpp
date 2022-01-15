#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

bool m[MxN][MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int max_x = 0, max_y = 0;
	while(N--) {
		int x, y;
		cin >> x >> y;
		m[y][x] = true;
		max_x = max(x, max_x);
		max_y = max(y, max_y);
	}

	auto dbgm = [&] {
		for(int y = 0; y <= max_y; ++y) {
			for(int x = 0; x <= max_x; ++x) {
				cerr << (m[y][x] ? '#' : '.');
			}
			cerr << endl;
		}
		cerr << endl;
	};

	int Q;
	cin >> Q;
	while(Q--) {
		char dir;
		int line;
		cin >> dir >> line;
		if (dir == 'x') {
			max_x = line - 1;
			for(int y = 0; y <= max_y; ++y) {
				for(int x = 0; x <= max_x; ++x) {
					m[y][x] |= m[y][2*max_x - x + 2];
				}
			}
		} else if (dir == 'y') {
			max_y = line - 1;
			for(int y = 0; y <= max_y; ++y) {
				for(int x = 0; x <= max_x; ++x) {
					m[y][x] |= m[2*max_y - y + 2][x];
				}
			}
		} else {
			cerr << "ERROR\n";
		}
	}


	dbgm();
	int total = 0;
	for(int y = 0; y <= max_y; ++y) {
		for(int x = 0; x <= max_x; ++x) {
			total += m[y][x];
		}
	}

	cout << total << endl;

	return 0;
}