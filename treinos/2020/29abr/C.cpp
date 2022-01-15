#include <bits/stdc++.h>
using namespace std;

#define MxN 1123

struct edge
{
	int i, j;
	int dist;
	edge() {};
	edge(int _i, int _j, int _dist) : i(_i), j(_j), dist(_dist) {};
};

int p[MxN], r[MxN];
pair<int,int> pos[MxN];
vector<edge> edges;
set<pair<int,int>> done;

bool cmp(const edge& e1, const edge& e2) { return e1.dist > e2.dist; }

int calcd(int i, int j) {
	int dx=pos[i].first-pos[j].first;
	int dy=pos[i].second-pos[j].second;
	return dx*dx+dy*dy;
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

void solve() {
	memset(p, 0, sizeof(p));
	memset(r, 0, sizeof(r));
	memset(pos, 0, sizeof(pos));
	done.clear();
	edges.clear();
	int N, M;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		p[i] = i;
		cin >> pos[i].first >> pos[i].second;
	}

	cin >> M;
	int a, b;
	for (int i = 1; i <= M; ++i) {
		cin >> a >> b;
		done.insert({a,b});
		done.insert({b,a});
		_union(a, b);
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i+1; j <= N; ++j) {
			if (done.count({i,j}) == 0) {
				edges.push_back(edge(i, j, calcd(i, j)));
			}
		}
	}
	sort(edges.begin(), edges.end(), cmp);

	int nsub = 0;
	for (int i = 1; i <= N; ++i) nsub += p[i] == i;
	if (nsub <= 1){
		cout << "No new highways need" << endl;
		return;
	}

	while (nsub > 1) {
		edge nxt = edges.back(); edges.pop_back();
		if (_find(nxt.i) != _find(nxt.j)) {
			_union(nxt.i, nxt.j);
			nsub--;
			cout << nxt.i << " " << nxt.j << endl;
		}
	}
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--) {
    	solve();
    	if (N) cout << endl;
    }
	return 0;
}