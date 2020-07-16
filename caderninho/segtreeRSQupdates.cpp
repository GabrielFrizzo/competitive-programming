#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

struct SegTree {
	vi V, lazy, st; int N;

	int left(int p) { return p<<1; }
	int right(int p) { return (p<<1)+1; }

	SegTree(const vi& _V) {
		V = _V; N = V.size();
		lazy.assign(4*N, 0);
		st.assign(4*N, 0);
		build(1, 0, N-1);
	}

	int build(int p, int l, int r) {
		int mid = (l+r)/2;

		if (l == r) return st[p] = V[l];
		int p1 = build(left(p), l, mid);
		int p2 = build(right(p), mid+1, r);

		return st[p] = p1+p2;
	}

	int query(int p, int l, int r, int i, int j) {
		int mid = (l+r)/2;

		if (i > r || j < l) return 0;
		if (l >= i && r <= j) return st[p];

		int p1 = query(left(p), l, mid, i, j);
		int p2 = query(right(p), mid+1, r, i, j);

		return p1+p2;
	}

	int upd(int p, int l, int r, int i, int j, int v) {
		int mid = (l+r)/2;

		if (i > r || j < l) return st[p];
		if (l == r) return st[p] = V[l] = v;
		int p1 = upd(left(p), l, mid, i, j, v);
		int p2 = upd(right(p), mid+1, r, i, j, v);

		return st[p] = p1+p2;
	}

	int inv(int p, int l, int r, int i, int j) {
		int mid = (l+r)/2;
		
		if (i > r || j < l) return st[p];
		if (l == r) return st[p] = V[l] = !V[l];
		int p1 = inv(left(p), l, mid, i, j);
		int p2 = inv(right(p), mid+1, r, i, j);

		return st[p] = p1+p2;
	}

	void upd(int i, int j, int v) {
		upd(1, 0, N-1, i, j, v); 
	}

	void inv(int i, int j) {
		inv(1, 0, N-1, i, j);
	}

	int query(int a, int b) {
		return query(1, 0, N-1, a, b);
	}
};


void solve() {
	int M;
	cin >> M;
	vi v;
	while (M--) {
		int T;
		string line;
		cin >> T;
		cin >> line;
		while (T--) {
			for (char c : line) {
				v.push_back(c-'0');
			}
		}
	}

	SegTree stree(v);
	int Q;
	cin >> Q;
	int nq = 1;
	while(Q--) {
		char op;
		int a, b;
		cin >> op >> a >> b;
		if (op == 'F') stree.upd(a, b, 1);
		if (op == 'E') stree.upd(a, b, 0);
		if (op == 'I') stree.inv(a, b);
		if (op == 'S') {
			cout << "Q" << nq++ << ": " << stree.query(a, b) << endl;
		}
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case " << i << ":\n";
    	solve();
    }
	return 0;
}