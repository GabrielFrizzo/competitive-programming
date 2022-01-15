#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
int N;

void solve() {
	vi v(N), pref(N+1);
	pref[0] = 0;
	int total = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		total += v[i];
		pref[i+1] = total;
	}

	for (int i = 0; i < N; ++i) {
		if (v[i] == pref[i]) {
			cout << v[i] << endl;
			return;
		}
	}

	cout << "nao achei\n";
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int l = 0;
	while(cin >> N) {
		cout << "Instancia " << ++l << endl;
		solve();		
		cout << endl;
	}		
	return 0;
}