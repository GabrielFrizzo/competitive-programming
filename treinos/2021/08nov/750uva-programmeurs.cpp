#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

int m[8];
int n_solution;
void print_solution() {
	cout << fixed << setw(2) << n_solution++ << "      ";
	for(int i = 0; i < 7; ++i) {
		cout << m[i]+1 << ' ';
	}
	cout << m[7]+1;
	cout << endl;
}

bool possible(int n, int j) {
	for(int i = 0; i < n; ++i) {
		if (m[i] == j) return false;
		if (abs(m[i] - j) == abs(i - n)) return false;
	}
	return true;
}

void backtrack(int n) {
	if (m[n] != -1) {
		if (possible(n, m[n])) {
			if (n == 7) {
				print_solution();
			} else {
				backtrack(n+1);
			}
		}
		return;
	}
	for(int i = 0; i < 8; ++i) {
		if (possible(n, i)) {
			m[n] = i;
			if (n == 7) {
				print_solution();
			} else {
				backtrack(n+1);
			}
		}
		m[n] = -1;
	}
}

void solve() {
	n_solution = 1;
	int a, b;
	cin >> a >> b;a--;b--;
	memset(m, -1, sizeof m);
	m[b] = a;

	backtrack(0);
}


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while(N--) {
		cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		solve();
		if (N)
			cout << endl;
	}

	return 0;
}