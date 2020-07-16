#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 1123;

int N, M;
int m[MxN][MxN];

const vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

void dfs(int i, int j) {
	if (!valid(i, j) || m[i][j] == 0) return;
	m[i][j] = 0;

	for (pii d : dir) {
		int ni = d.first+i, nj = d.second+j;
		dfs(ni, nj);
	}
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < M; ++j) {
    		cin >> m[i][j];
    	}
    }

	int res = 0;
	for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < M; ++j) {
    		if (m[i][j]) {
    			res++;
    			dfs(i, j);
    		}
    	}
    }    

    cout << res << endl;

	return 0;
}