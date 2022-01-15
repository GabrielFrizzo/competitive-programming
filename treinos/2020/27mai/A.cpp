#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int N, M;

vector<pii> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

void solve() {
	vector<vi> g(N, vi(M));
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < M; ++j) {
    		cin >> g[i][j];
    	}
    }
    vector<pii> res;
	for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < M; ++j) {
    		bool good = true;
    		for (pii d : directions) {
    			int ni = i+d.first, nj = j+d.second;
    			if (valid(ni, nj) && g[ni][nj] >= g[i][j]) {
    				good = false;
    				break;
    			}

    		}
    		if (good) res.push_back({i, j});
    	}
    }

    if (res.size() > 0) {
    	for (pii p : res)
    		cout << p.first+1 << ' ' << p.second+1 << endl;

    } else {
    	cout << -1 << endl;
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> N >> M) {
    	solve();
    }

    
	return 0;
}