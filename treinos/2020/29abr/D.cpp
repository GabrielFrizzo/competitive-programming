#include <bits/stdc++.h>
using namespace std;

#define MxN 112
#define MxM MxN*MxN

struct edge
{
	int i, j;
	int dist;
	edge() {};
	edge(int _i, int _j, int _dist) : i(_i), j(_j), dist(_dist) {};
};

int p[MxN], r[MxN], N, M;

void _ufinit() {
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= N; ++i) p[i] = i;
}

int _find(int i) {
	if (p[i] == i) return i;
	return p[i] = _find(p[i]);
}

void _union(int i, int j) {
	int a = _find(i), b = _find(j);
	if (a == b) return;
	if (r[a] > r[b]) p[b] = a;
	else {p[a] = b;r[b] = max(r[b], r[a]+1);}
}

bool cmp(const edge& e1, const edge& e2) { return e1.dist < e2.dist; }

void solve() {
	cin >> N >> M;
	vector<edge> edges;
	edges.clear();

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}
	sort(edges.begin(), edges.end(), cmp);

	int i = 0, ncomp = N;
	int cost = 0;
	vector<int> kruskal;
	kruskal.clear();
	_ufinit();
	while (ncomp > 1) {
		edge nxt = edges[i];
		if (_find(nxt.i) != _find(nxt.j)) {
			_union(nxt.i, nxt.j);
			ncomp--;
			cost += nxt.dist;
			kruskal.push_back(i);
		}
		++i;
	}

	cout << cost << " ";
	int sbest = 1e9;
	
	for (int k : kruskal) {
		_ufinit();
		int cost = 0, i = 0;
		ncomp = N;
		while (ncomp > 1) {
			i += (i == k);
			if (i >= M) {cost = 1e9; break;}
			edge nxt = edges[i];
			if (_find(nxt.i) != _find(nxt.j)) {
				_union(nxt.i, nxt.j);
				ncomp--;
				cost += nxt.dist;
			}
			++i;
		}
		sbest = min(sbest, cost);
	}

	cout << sbest << endl;

}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    	solve();
	return 0;
}