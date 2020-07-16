#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vi v(N);
    for (int i = 0; i < N; ++i) {
    	char c;
    	cin >> c;
    	v[i] = c-'0';
    }

	int total = 0;
	int i;
	int limit = ceil(N/2.);
	for (i = 0; i < limit; ++i) {
		total += v[i];
	}

	int best = total;
	for (; i < N; ++i) {
		total -= v[i-limit];
		total += v[i];
		best = max(best, total);
	}

	cout << best << endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	solve();
    }
	return 0;
}