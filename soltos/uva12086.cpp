// RSQ BIT

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int N;

struct BIT {
	vi bit;

	int rsq(int b) {
		int sum = 0;
		for (; b; b -= b&-b)
			sum += bit[b];
		return sum;
	}

	int rsq(int a, int b) {
		return rsq(b) - (a == 1 ? 0 : rsq(a-1));
	}

	void adjust(int k, int v) {
		for (; k < (int)bit.size(); k += k&-k)
			bit[k] += v;
	}

	void update(int k, int v) {
		adjust(k, v-rsq(k, k));
	}

	BIT(const vi &V) {
		int n = V.size();
		bit.assign(n+1, 0);
		for (int i = 0; i < n; ++i) adjust(i+1, V[i]);
	}
};

void solve() {
	vi V(N);
	for (int i = 0; i < N; ++i) cin >> V[i];

	BIT bit(V);
	string op;
	while (cin >> op, op != "END") {
		if (op == "S") {
			int k, v;
			cin >> k >> v;
			bit.update(k, v);
		}
		if (op == "M") {
			int a, b;
			cin >> a >> b;
			cout << bit.rsq(a, b) << endl;
		}
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool first = true;
    int TC = 1;
    while (cin >> N, N) {
    	if (!first) cout << endl;
    	cout << "Case " << TC++ << ':' << endl;
    	solve();
    	first = false;
    }
	return 0;
}