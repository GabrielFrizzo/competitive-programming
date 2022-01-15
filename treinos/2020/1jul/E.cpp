#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MAX = 1e9;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a >= c) {
		cout << -1 << ' ';
	} else {
		cout << 1 << ' ';
	}

	if (1LL*b*a <= c) {
		cout << -1 << endl;
	} else {
		cout << b << endl;
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while(TC--) {
    	solve();
    }
	return 0;
}