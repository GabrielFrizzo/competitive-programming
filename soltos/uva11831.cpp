#include <bits/stdc++.h>
using namespace std;

int N, M, S;

typedef struct {
	int x, y, d;
} pos;

pair<int,int> adv(pos pinit) {
	if (pinit.d == 0) pinit.x++;
	else if (pinit.d == 1) pinit.y--;
	else if (pinit.d == 2) pinit.x--;
	else if (pinit.d == 3) pinit.y++;
	return {pinit.x, pinit.y};
}

void solve() {
	vector<vector<char>> mat(N, vector<char>(M));
	pos pinit;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == 'L') pinit = {j,i,0};
			else if (mat[i][j] == 'N') pinit = {j,i,1};
			else if (mat[i][j] == 'O') pinit = {j,i,2};
			else if (mat[i][j] == 'S') pinit = {j,i,3};
		}
	}

	int res = 0;
	while (S--) {
		// cout << res << " " << pinit.x << " " << pinit.y << endl;
		char d;
		cin >> d;
		if (d == 'F') {
			pair<int, int> nxpos = adv(pinit);
			if (!(nxpos.second < 0 || nxpos.first < 0 || nxpos.second >= N || nxpos.first >= M || mat[nxpos.second][nxpos.first] == '#')) {
				pinit.x = nxpos.first;
				pinit.y = nxpos.second;
			}


		}
		else if (d == 'D') pinit.d = (pinit.d + 3)%4;
		else if (d == 'E') pinit.d = (pinit.d + 1)%4;
		if (mat[pinit.y][pinit.x] == '*') {
			res++;
			mat[pinit.y][pinit.x] = '.';
		}
	}

	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> N >> M >> S, S!=0)
    	solve();

	return 0;
}