#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;


void solve() {
	int N, A, B, C;
	cin >> N >> A >> B >> C;

	vi res(5);
	for (res[0] = 1; res[0] <= N; ++res[0]) {
		for (res[1] = 1; res[1] <= N; ++res[1]) {
			for (res[2] = 1; res[2] <= N; ++res[2]) {
				for (res[3] = 1; res[3] <= N; ++res[3]) {
					for (res[4] = 1; res[4] <= N; ++res[4]) {
						int best = 0, cntA = 0, cntB = 0, cntC = 0, best2 = 0;
						for (int i = 0; i < N; ++i) {
							if (res[i] > best) {
								best = res[i];
								cntA++;
								cntC = 1;
							} else if (res[i] == best) {
								cntA++;
								cntC++;
							}

							if (res[N-i-1] >= best2) {
								best2 = res[N-i-1];
								cntB++;		
							}
						}

						// cout << cntA << ' ' << cntB << ' ' << cntC << endl;
						if (cntA == A && cntB == B && cntC == C) {
							for (int i = 0; i < N; ++i) {
								cout << res[i] << ' ';
							}
							cout << endl;
							return;
						}
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
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