#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

struct SegTree {
	vi V; int N;
	vector<ll> st, lazy;

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
		ll p1 = build(left(p), l, mid);
		ll p2 = build(right(p), mid+1, r);

		return st[p] = p1+p2;
	}

	int query(int p, int l, int r, int i, int j) {
		if (i > r || j < l) return 0;
		propagate(p, l, r);
		if (l >= i && r <= j) return st[p];

		int mid = (l+r)/2;
		ll p1 = query(left(p), l, mid, i, j);
		ll p2 = query(right(p), mid+1, r, i, j);

		return p1+p2;	
	}

	int query(int i) {
		return query(1, 0, N-1, i, i);
	}

	int upd(int p, int l, int r, int i, int j, int v) {
		propagate(p, l, r);
		if (i > r || j < l) return st[p];
		if (l >= i && r <= j) {
			lazy[p] += v;
			propagate(p, l, r);
			return st[p];
		}

		int mid = (l+r)/2;
		ll p1 = upd(left(p), l, mid, i, j, v);
		ll p2 = upd(right(p), mid+1, r, i, j, v);

		return st[p] = p1+p2;		
	}

	void upd(int i, int j, int v) {
		upd(1, 0, N-1, i, j, v);
	}

	void propagate(int p, int l, int r) {
		if (!lazy[p]) return;
		if (l != r) {
			lazy[left(p)] += lazy[p];
			lazy[right(p)] += lazy[p];
		}
		st[p] += (r-l+1)*lazy[p];
		lazy[p] = 0;
	}
};


int N;

void solve() {
	bool halt = false;
	int op = -1;
	int inp;
	vi v(1e6);

	SegTree st(v);

	while (N--) {
		cin >> inp;
		if (!halt) {
			op = inp;
			if (op == 18) {
				int A, B, I;
				cin >> A >> B >> I; N-=3;
				st.upd(A, B, I);
				debug() << imie(st.st);
			} else if (op == 42) {
				int P;
				cin >> P;N--;
				ll ans = st.query(P) - st.query(P-1);
				if (ans < 0) cout << ' ';
				else cout << (char)('A'+(ans%26));
				debug() << imie(st.st);
			} else {
				halt = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N, N) {
    	cout << "MENSAGEM: [";
    	solve();
    	cout << "]\n";
    }
	return 0;
}
