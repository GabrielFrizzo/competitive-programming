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

const int MxN = 5123;
const int MxD = 1123;
const int LOG = 15;

vi tree[MxN], selling;
int V[MxN], lvl[MxN], par[MxN][LOG];
ll dp[MxN][MxD], sum[MxN];

void dfs(int u, int p) {
	lvl[u] = lvl[p]+1;
	par[u][0] = p;
	for (int h = 1; h < LOG; ++h) {
		if (par[u][h-1] > -1)
			par[u][h] = par[par[u][h-1]][h-1];
	}

	for (int v : tree[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
}

int lca(int x, int y) {
	if (lvl[x] > lvl[y]) swap(x, y);

	for (int i = LOG-1; i >= 0; --i) {
		int nxt = par[y][i];
		if (nxt != -1 && lvl[nxt] >= lvl[x])
			y = nxt;
	}

	if (x == y) return x;

	for (int i = LOG-1; i >= 0; --i) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}

	return par[x][0];
}

void upd(int x, int y, int l) {
	sum[x] += l; sum[y] += l;
	int _lca = lca(x, y);
	debug() << imie(x) imie(y) imie(_lca);
	sum[_lca] -= l;
	sum[par[_lca][0]] -= l;
}

int difftree(int u, int p) {
	int aux = 0;
	for (int v : tree[u]) {
		if (v != p) {
			aux += difftree(v, u);
		}
	}

	return sum[u] = aux + sum[u];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, D;
    cin >> N >> D;

    for (int i = 0; i < N-1; ++i) {
    	int u, v; cin >> u >> v;
    	tree[u].push_back(v);
    	tree[v].push_back(u);
    }
    tree[0].push_back(1);tree[1].push_back(0);

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
    	int inp; cin >> inp;
    	selling.push_back(inp);
    	cin >> V[inp];
    }

    memset(par, -1, sizeof par);
    lvl[0] = 0;
    dfs(0, 0);

    int Q; cin >> Q;
    while (Q--) {
    	int x, y, l;
    	cin >> x >> y >> l;
    	upd(x, y, l);
    }

    difftree(0, 0);

    // for (int i = 0; i <= N; ++i) cout << i << ' ' << sum[i] << endl;
    //knapsack
    for (int i = 0; i <= M; ++i) {
    	for (int d = 0; d <= D; ++d) {
    		if (!i || !d) {
    			dp[i][d] = 0;
    			continue;
    		}
    		dp[i][d] = dp[i-1][d];

    		if (V[selling[i-1]] <= d) {
                debug() << imie(i) imie(sum[i]);
    			dp[i][d] = max(dp[i][d], dp[i-1][d-V[selling[i-1]]]+sum[selling[i-1]]);
            }

    		// cout << dp[i][d] << ' ';
    	}
    	// cout << endl;
    }

    cout << dp[M][D] << endl;

	return 0;
}