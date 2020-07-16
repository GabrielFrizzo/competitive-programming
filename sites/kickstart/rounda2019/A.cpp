#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
    int N, P;
    cin >> N >> P;
    vi v(N);
    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    }
    sort(v.begin(), v.end());

    int total = 0;
    for (int i = 0; i < P-1; ++i) {
    	total += v[P-1]-v[i];
    }

    int best = total;
    // cout << total << endl;
    for (int i = 0; i+P < N; ++i) {
    	total -= v[i+P-1] - v[i];
    	total += (P-1)*(v[i+P]-v[i+P-1]);
    	// cout << total << endl;
    	best = min(best, total);
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