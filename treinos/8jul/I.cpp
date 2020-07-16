#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 11234;

int v[MxN];
int n;
vector<pii> sols;


void stch(int i, int j) {
	cout << i << ' ' << j << endl;
	sols.push_back({i,j});
	int half = ceil((i+j)/2.) - 1;
	for (int ii = i; ii < half; ++ii) {
		swap(v[ii], v[ii+half]);
	}
}

int place(int curr) {
	if (v[curr] == curr) return 0;
	int pos;
	int sz = n-curr+1;
	for (pos = curr; pos < curr+ceil(sz/2.); ++pos) {
		if (v[pos] == curr) {
			cout << curr << "asd" << pos+pos-curr-1 << endl;
			stch(curr, pos+pos-curr-1);
			return 1;
		}
	}

	for (; pos <= n; ++pos) {
		if (v[pos] == curr) {
			cout << curr << "dsa" << pos+((curr-pos+1)&1) << endl;
			stch(curr, pos+((curr-pos+1)&1));
			stch(curr, curr+sz/2);
			return 2;
		}
	}

	cout << curr << endl;
	assert(false);
	return 2;
}

void solve() {
	cin >> n;
	sols.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += place(i);
		for (int j = 1; j <= n; ++j)
			cout << v[j] << ' ';
		cout << endl;
	}

	cout << res << endl;
	for (pii p : sols) {
		cout << p.first << ' ' << p.second << endl;
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