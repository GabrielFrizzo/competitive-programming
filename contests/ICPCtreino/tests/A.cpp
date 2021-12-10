#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MxN = 112;

bitset<MxN> memo[MxN];
int counts[MxN];
bool visited[MxN];
pii parents[MxN];
int a, b;

void recursion (int a_) {

	recursion(parents[a_].first);
	recursion(parents[a_].second);
	if (visited[a_]) return;
	visited[a_] = true;

	if (a_ != b)
		cout << 1 <<' '<< a_ <<'\n';
}

int main() {
	cin >> a >> b;
	if (a!=1) {
		cout << "*\n";
		return 0;
	}

	for (int i = 0; i < MxN; ++i) counts[i] = 1234;
		counts[1] = 0;

	for (int i = 1; i <= b; ++i) {
		for (int j = 1; j <= i/2; ++j) {
			bitset<MxN> total = memo[j] | memo[i-j];
			total.set(j);
			total.set(i-j);
			int cnt = total.count();
			if (cnt < counts[i]) {
				memo[i] = total;
				counts[i] = cnt;
				parents[i] = {j, i-j};
			}
		}
	}
	// for (int i = 1; i <= b; ++i) {
	// 	cout << parents[i].first << ' ' << parents[i].second << endl;
	// }

	recursion(b);
	return 0;
}