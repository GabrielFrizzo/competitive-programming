#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 212345;
const int INF = 1e9+7;

int v[MxN];
int N, Q;

void qry(int a, int b) {
	vi lft(N+1), rt(N+1);
	for (int i = 0; i <= N; ++i) {
		lft[i] = i-1;
		rt[i] = i;
	}
	lft[0] = 0;


	int ans = a;
	b--;
	while (b--) {
		// cout << ans << ' ' << lft[a] << ' ' << rt[a] << endl;
		if (v[lft[a]] < v[rt[a]]) {
			ans = lft[a]--;
		} else {
			ans = ++rt[a];
		}
	}

	cout << ans << ' ';
}

void solve() {
    cin >> N >> Q;

    for (int i = 1; i < N; ++i) {
    	cin >> v[i];
    }
    v[0] = v[N] = INF;

    while (Q--) {
    	int a, b;
    	cin >> a >> b;
    	qry(a, b);
    }

    cout << endl;
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