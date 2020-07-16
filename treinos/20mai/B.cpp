#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using adjlist = vector<vi>;
const int N = 26;
const int INF = 1e9+5;
int M;

void fwarsh(adjlist& graph) {
	for (int i = 0; i < N; ++i) graph[i][i] = 0;

	for (int w = 0; w < N; ++w) {
		for (int u = 0; u < N; ++u) {
			for (int v = 0; v < N; ++v) {
				graph[u][v] = min(graph[u][v], graph[u][w]+graph[w][v]);
			}
		}
	}
}

void solve() {
	adjlist g1(N, vi(N, INF)), g2(N, vi(N, INF));

    while(M--) {
    	char a, b, c, d;
    	int cost;
    	scanf(" %c %c %c %c %d", &a, &b, &c, &d, &cost);
    	int u = c-'A', v = d-'A';
    	if (a == 'Y') {
    		g1[u][v] = cost;
    		if (b == 'B')
    			g1[v][u] = cost;
    	} else {
			g2[u][v] = cost;
			if (b == 'B')
				g2[v][u] = cost;
    	}
    }

    fwarsh(g1);
    fwarsh(g2);

   
    char p1, p2;
    scanf(" %c %c", &p1, &p2);
    int pos1=p1-'A', pos2=p2-'A';

    vi bests;
    int best = INF;
    for (int i = 0; i < N; ++i) {
    	if (g1[pos1][i]+ g2[pos2][i] < best) {
    		bests.clear();
    		bests.push_back(i);
    		best = g1[pos1][i]+ g2[pos2][i];
    	} else if (g1[pos1][i]+ g2[pos2][i] == best) {
    		bests.push_back(i);
    	}
    }

    // for (vi v : g1) {
    // 	for (int i : v) {
    // 		cout << i << ' ';
    // 	}
    // 	cout << endl;
    // }
    int first = 1;
    if (best == INF) {
    	printf("You will never meet.");
    } else {
    	printf("%d ", best);
	    for (int i : bests) {
	    	char c = i+'A';
	    	printf("%s%c",first?"":" ",c);
	    }
    }
}

int main(int argc, char const *argv[])
{
    int first = 1;
    while(scanf("%d", &M), M) {
    	printf("%s",first?"":"\n");
        solve();
        first = 0;
    }
    

	return 0;
}