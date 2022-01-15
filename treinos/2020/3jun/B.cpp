#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int h, u, d, f, du;

void solve() {
	du = f*u;
	h*=100, u*=100, d*=100;
	int climbed = 0, day;
	for (day = 1; climbed >= 0; day++) {
		climbed += u;
		if (climbed > h) {
			cout << "success on day " << day << endl;
			return;
		}
		u = max(0, u-du);
		climbed -= d;
	}

	cout << "failure on day " << day-1 << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> h >> u >> d >> f, h) {
    	solve();
    }
	return 0;
}