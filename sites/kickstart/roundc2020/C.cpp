#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

unordered_set<int> squares;

bool square(int i) {
	return squares.count(i) != 0;
}

void solve() {
    int N;
    cin >> N;
    vi v(N);
    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    }

    vi pref(N+1, 0);
    int total = 0;
    for (int i = 1; i <= N; ++i) {
    	total += v[i-1];
    	pref[i] = total;
    }

    int res = 0;
    for (int i = 1; i <= N; ++i) {
    	for (int j = i; j <= N; ++j) {
    		res += (square(pref[j]-pref[i-1]));
    	}
    }

    cout << res << endl;
}

void calc_squares() {
	for (int i = 0; i < 1000; ++i) {
		squares.insert(i*i);
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    calc_squares();

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	solve();
    }
	return 0;
}