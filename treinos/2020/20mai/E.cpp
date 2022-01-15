#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

struct SegTree {
	vi V, st, lazy;
	int N;

	int left(int p) { return p<<1; }
	int right(int p) { return (p<<1)+1; }

	SegTree(const vi& _V) {
		V = _V; N = V.size();
		st.assign(N*4, 0);
		lazy.assign(N*4, -1);
		build(1, 0, N-1);
	}

	int build(int p, int l, int r) {
		if (l == r) return st[p] = V[l];

		int mid = (l+r)/2;
		int p1 = build(left(p), l, mid);
		int p2 = build(right(p), mid+1, r);

		return st[p] = p1+p2;
	}

	int qry(int p, int l, int r, int i, int j) {
		if (i > r || j < l) return 0;
		propagate(p, l, r);
		if (l >= i && r <= j) return st[p];
		int mid = (l+r)/2;
		int p1 = qry(left(p), l, mid, i, j);
		int p2 = qry(right(p), mid+1, r, i, j);

		return p1+p2;
	}

	int qry(int i, int j) {
		return qry(1, 0, N-1, i, j);
	}

	int upd(int p, int l, int r, int i, int j, int v) {
		propagate(p, l, r);
		if (i > r || j < l) return st[p];
		if (l >= i && r <= j) {
			lazy[p] = v;
			propagate(p, l, r);
			return st[p];
		}

		int mid = (l+r)/2;
		int p1 = upd(left(p), l, mid, i, j, v);
		int p2 = upd(right(p), mid+1, r, i, j, v);

		return st[p] = p1+p2;
	}

	void upd(int i, int j, int v) {
		upd(1, 0, N-1, i, j, v);
	}

	int inv(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (i > r || j < l) return st[p];
		if (l >= i && r <= j) {
			lazy[p] = 2;
			propagate(p, l, r);
			return st[p];
		}

		int mid = (l+r)/2;
		int p1 = inv(left(p), l, mid, i, j);
		int p2 = inv(right(p), mid+1, r, i, j);

		return st[p] = p1+p2;
	}

	void inv(int i, int j) {
		inv(1, 0, N-1, i, j);
	}

	void pushv(int p, int l, int r) {
		if (l == r) return;
		lazy[left(p)] = lazy[right(p)] = lazy[p];
	}

	void pushinv(int p) {
		if (p >= (int)lazy.size()) return;
		if (lazy[p] == -1) lazy[p] = 2;
		else if (lazy[p] == 0) lazy[p] = 1;
		else if (lazy[p] == 1) lazy[p] = 0;
		else if (lazy[p] == 2) lazy[p] = -1;
	}

	void propagate(int p, int l, int r) {
		if (lazy[p] == 0) {
			pushv(p, l, r);
			st[p] = 0;
		}
		else if (lazy[p] == 1) {
			pushv(p, l, r);
			st[p] = r-l+1;
		}
		else if (lazy[p] == 2) {
			pushinv(left(p));pushinv(right(p));
			st[p] = r-l+1-st[p];
		}
		lazy[p] = -1;
	}
};

void solve() {
	int M;
	cin >> M;
	vi v;
	while (M--) {
		int n;
		string line;
		cin >> n;
		cin >> line;
		while (n--) {
			for (char c : line) {
				v.push_back(c-'0');
			}
		}
	}

	SegTree stree(v);

	int Q, nq = 1;

	cin >> Q;
	while(Q--) {
		char op;
		int a, b;
		cin >> op >> a >> b;
		if (op == 'E') stree.upd(a, b, 0);
		if (op == 'F') stree.upd(a, b, 1);
		if (op == 'I') stree.inv(a, b);
		if (op == 'S') {
			cout << "Q" << nq++ << ": " << stree.qry(a, b) << endl;
		}
		// for (int i : stree.st)
		// 	cout << i << ' ';
		// cout << endl;
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