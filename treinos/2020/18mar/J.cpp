#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

struct state {
	int x, y, t;
	state() {}
	state (int a, int b, int c) : x(a), y(b), t(c) {}
};

int N, M, K;

void solve() {
	vector<state> v(K+1);
	for (int i = 1; i <= K; ++i) {
		cin >> v[i].x >> v[i].y >> v[i].t;
	}

	int x, y;
	cin >> x >> y;
	v[0] = {x, y, 0};


	auto cango = [&] (int i, int j) {
		int dx = abs(v[i].x - v[j].x), dy = abs(v[i].y - v[j].y);
		return max(dx, dy) <= v[j].t - v[i].t;
	};

	vi dp(K+1, -1);
	dp[0] = 0;
	int best = 0;
	for (int i = 1; i <= K; ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[j] != -1 && cango(j, i)) {
				dp[i] = max(dp[i], dp[j]+1);
				best = max(best, dp[i]);
			}
		}
	}
	
	cout << best << endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> N >> M >> K, N) {
    	solve();
    }
    
	return 0;
}