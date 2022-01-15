#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

bool ispalinbase(int N, int b) {
	vi ans;
	while (N) {
		ans.push_back(N%b);
		N /= b;
	}

	int S = ans.size();
	for (int i = 0; i < S; ++i) {
		if (ans[i] != ans[S-i-1]) {
			return false;
		}
	}
	return true;
}

void solve() {
	int N;
	cin >> N;
	vi ans;
	for (int i = 2; i <= 16; ++i) {
		if (ispalinbase(N, i)) {
			ans.push_back(i);
		}
	}

	if (ans.size() == 0) {
		cout << -1 << endl;
	}
	else {
		bool start = true;
		for (int i : ans) {
			if (!start) {
				cout << " ";
			}
			cout << i;
			start = false;
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
		solve();
    }
	return 0;
}