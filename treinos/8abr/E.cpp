#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x, inp;
	set<int> a;

	cin >> n >> x;

	while (n--) {
		cin >> inp;
		a.insert(inp);
	}

	int v = 1;

	while (x) {
		if (a.find(v) == a.end()) {
			a.insert(v);
			x--;
		}
		v++;
	}

	while (a.find(v) != a.end()) {
		v++;
	}

	cout << v - 1 << endl;
}



int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    while (T--) {
    	solve();
    }
	return 0;
}