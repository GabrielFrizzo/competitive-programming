#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112;

int M, N;
char g[MxN][MxN];
bool vis[MxN][MxN];

vector<pii> directions = {{0,0}, {0,1}, {0,-1},
						  {-1,0}, {-1,1}, {-1,-1},
						  {1,0}, {1,1}, {1,-1}};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

int dfs(int i, int j) {
	if (vis[i][j] || g[i][j] == 'L') return 0;
	vis[i][j] = true;

	int ans = 0;
	for (pii d : directions) {
		int ni = d.first + i, nj = d.second+j;
		if (valid(ni, nj))
			ans += dfs(ni, nj);
	}

	return ans+1;
}

void solve() {
	string line;
	N = 0;
	while (getline(cin, line), !isdigit(line[0])) {
		// cout << line << endl;
		M = line.size();
		for (int i = 0; i < M; ++i) {
			g[N][i] = line[i];
		}
		N++;
	}

	do {
		stringstream ss(line);
		int i, j; ss >> i >> j;i--; j--;
		// cout << i << ' ' << j << endl;
		memset(vis, false, sizeof vis);
		cout << dfs(i, j) << endl;
	} while(getline(cin, line), !line.empty());
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;cin.ignore();cin.ignore();
    bool first = true;
    while (TC--) {
    	if (!first) cout << endl;
    	solve();
    	first = false;
    }
	return 0;
}