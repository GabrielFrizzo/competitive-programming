#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112345;
int N, M, K;

vector<pii> g[MxN];
int dist[MxN];
int acum[MxN], cnt[MxN];

void dij() {
	priority_queue<piii> pq;
	pq.push({0, {N-1, N-1}});
	dist[N-1] = 0;
	acum[N-1] = 0;
	cnt[N-1] = 1;

	while (!pq.empty()) {
		pii u; int cost;
		tie(cost, u) = pq.top(); pq.pop();
		if (cost > dist[u.first]) continue;
		for (pii v: g[u.first]) {
			if (cost + v.first < dist[v.second]) {
				dist[v.second] = cost + v.first;
				acum[v.second] = acum[u.first] + cost;
				cnt[v.second] = cnt[u.first] + 1;
				pq.push({dist[v.second], {v.second, u.first}});
			}
		}
	}
}

void solve() {
	cin >> N >> M >> K;
	
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({c, b});
		g[b].push_back({c, a});
	}
	for (int i = 0; i < MxN; ++i) dist[i] = 1e9;
	dij();

	vector<pii> edges;
	for (int i = 0; i < M; ++i) {
		edges.push_back({dist[i], i});
	}
	sort(edges.begin(), edges.end());

	// for (pii i : edges) cout << i.first << ' ' << i.second << endl;
	double best = 1e9;
	for (int i = 0; i < M; ++i) {
		best = min(best, (acum[edges[i].second]+K*N)/(double)cnt[edges[i].second]);
		// cout << acum+K*N << " aaa " << best << endl;
	}

	cout << fixed << setprecision(3) << best << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;
	while(TC--) {
		solve();
	}
	return 0;
}

// 0 			1 				2 	3
//   200      200	 	  1

// custo_do_aviao 100
// 200 + 1/2 = 200.5

// só aviao 400
// Somatorio min(caminho p final, preço passagem)



// 0 	1 	2
//  10   5
//  	 20

// custo aviao = 1

// 3

// nunca vale a pena    barco -> aviao
// as vezes vale a pena aviao -> barco 


// dist(i, final) < custo_aviao