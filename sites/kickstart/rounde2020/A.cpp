#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;


void solve() {
	int N;
	cin >> N;
	int inp, last;
	cin >> last;
	cin >> inp;
	int curr = last - inp;
	int cnt = 2;
	int best = cnt;
	for (int i = 2; i < N; ++i) {
		last = inp;
		cin >> inp;
		if (curr == last - inp) {
			cnt++;
			best = max(best, cnt);
		} else {
			cnt = 2;
			curr = last - inp;
		}
	}

	cout << best << endl;

}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}