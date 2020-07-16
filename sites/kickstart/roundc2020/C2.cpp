#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

vector<int> squares;
int N;

ll search(vi& v, int square) {
    int r = 1, l = 0;
    ll res = 0;
    int total = v[0];
    while (r < N) {
        if (total == square) {
            res++;
            total -= v[l++];
        } else if (total < square)
    }

    return res;
}

void solve() {
    cin >> N;
    vi v(N);
    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    }

    ll total = 0;
    for (int square : squares) {
        total += search(v, square);
    }

    cout << total << endl;
}

void calc_squares() {
	for (int i = 0; i < 5000; ++i) {
		squares.push_back(i*i);
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