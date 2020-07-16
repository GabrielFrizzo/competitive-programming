#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 212345;
int v[MxN];

void solve() {
    int N;
    cin >> N;

    for (int i =0; i < N; ++i) {
    	cin >> v[i];
    }

    int ans = 0;
    int m = -1;
    for (int i = 0; i < N-1; ++i) {
    	if (v[i] > m && v[i] > v[i+1]) {
    		ans++;
    	}
    	m = max(m, v[i]);
    }

    if (v[N-1] > m) ans++;

    cout << ans << endl;
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