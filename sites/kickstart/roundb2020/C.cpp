#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using pll = pair<ll, ll>;

const int MAX = 1e9;

pll paren() {
	char c;
	pll res = {0,0};
	while ((c = getchar()) != '\n' && c != ')') {
		if (c >= '0' && c <= '9') {
			int nc = c-'0';
			assert(getchar() == '(');
			ll x, y;
			tie(x, y) = paren();
			res.first += x*nc;
			res.second += y*nc;
		}
		else {
			if (c == 'N') res.second--;
			if (c == 'S') res.second++;
			if (c == 'E') res.first++;
			if (c == 'W') res.first--;
		}
		res.first = (res.first + MAX) % MAX;
		res.second = (res.second + MAX) % MAX;
	}

	// printf("%d %d\n", res.first, res.second);
	return res;
}

void solve() {
	pll res = paren();
	printf("%lld %lld\n", res.first+1, res.second+1);
}

int main(int argc, char const *argv[])
{
    int TC;
    scanf("%d ", &TC);
    for (int i = 1; i <= TC; ++i) {
    	printf("Case #%d: ", i);
    	solve();
    }

	return 0;
}