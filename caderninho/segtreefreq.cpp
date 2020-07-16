// SegTree Frequencies
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int INF = 1e9+5;

struct Node {
	int l_f, l, p, r_f, r;
	Node() {};
	Node(int _l_f, int _l, int _p, int _r_f, int _r) : l_f(_l_f), l(_l), p(_p), r_f(_r_f), r(_r) {}

	Node merge(Node& other) {
		Node res = Node(l_f, l,
						max(p, other.p),
						other.r_f, other.r);
		if (r == other.l && r_f + other.l_f > res.p) {
			res.p = r_f + other.l_f;
			if (r == res.r) {res.r_f = res.p;}
			if (r == res.l) {res.l_f = res.p;}
		}
		return res;
	}
};

struct SegTree {
	vi V;
	vector<Node> st;
	int N;
	int left(int p) { return p<<1; }
	int right(int p) { return (p<<1)+1; }

	Node build(int p, int l, int r) {
		if (r == l)
			return st[p] = Node(1, V[l], 1, 1, V[r]);
		else {
			int mid = (l+r)/2;
			Node p1 = build(left(p), l, mid);
			Node p2 = build(right(p), mid+1, r);
			return st[p] = p1.merge(p2);
		}
	}

	Node rmq(int p, int l, int r, int i, int j) {
		if (i > r || j < l) return Node(-INF, -INF, -INF, -INF, -INF);
		if (l >= i && r <= j) return st[p];

		int mid = (l+r)/2;
		Node p1 = rmq(left(p), l, mid, i, j);
		Node p2 = rmq(right(p), mid+1, r, i, j);

		return p1.merge(p2);
	}

	int rmq(int i, int j) {
		Node res = rmq(1, 0, N-1, i, j);
		// cout << res.first << " " << res.second << endl;
		return res.p;
	}

	SegTree(const vi &_V) {
		V = _V; N = V.size();
		st.assign(4*N, Node());
		build(1, 0, N-1);
	}
};

int n, q;

void solve() {
	vi inp(n);
	for (int i = 0; i < n; ++i)
		cin >> inp[i];

	SegTree stree(inp);
	// for (Node i : stree.st) cout << i.p << " ";
	// cout << endl;
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << stree.rmq(i-1, j-1) << endl;
	}
}

int main(int argc, char const *argv[])
{
	while (cin >> n, n) {
		cin >> q;
		solve();
	}
	return 0;
}
