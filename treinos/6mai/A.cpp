#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;

const int MxN = 112;

struct state {
	int row, col;
	int cost;
	int keys;

	state() {}
	state(int _row, int _col, int _cost, int _keys) : row(_row), col(_col), cost(_cost), keys(_keys) {}
};


int N, M;

int keybin(char key) {
	if (key == 'a' || key == 'A') return 1;
	if (key == 'b' || key == 'B') return 1<<1;
	if (key == 'c' || key == 'C') return 1<<2;
	if (key == 'd' || key == 'D') return 1<<3;
	if (key == 'e' || key == 'E') return 1<<4;
	if (key == 'f' || key == 'F') return 1<<5;
	if (key == 'g' || key == 'G') return 1<<6;
	return 0;
}


char m[MxN][MxN];
bool visited[MxN][MxN][128];

bool valid(int r, int c) {
	return r >= 0 && c >= 0 && r < N && c < M;
}

bool isdoor(char c) {
	return c >= 'A' && c <= 'G';
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	N = 0;
	string line;
	while (cin >> line) {
		M = line.size();
		for (int i = 0; i < M; i++)
			m[N][i] = line[i];
		N++;
	}

	// for (int i = 0; i < N; ++i) {
	// 	for (int j = 0; j < M; ++j) {
	// 		cout << m[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	pii ipos;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (m[i][j] == '@') {
				ipos = {i, j};
				m[i][j] = '.';
			}

	queue<state> q;
	q.push(state(ipos.first, ipos.second, 0, 0));
	vector<pii> directions = {{1,0},{0,-1},{0,1},{-1,0}};

	memset(visited, 0, sizeof(visited));
	while (!q.empty()) {
		state curr = q.front(); q.pop();
		// cout << curr.row << " " << curr.col << endl;
		if (visited[curr.row][curr.col][curr.keys]) continue;
		visited[curr.row][curr.col][curr.keys] = true;
		if (m[curr.row][curr.col] == '*') {cout << curr.cost << endl; exit(0);}

		for (pii d : directions) {
			state nxt = state(curr.row+d.first, curr.col+d.second, curr.cost+1, curr.keys);
			if (!valid(nxt.row, nxt.col)   ||
				m[nxt.row][nxt.col] == '#' ||
				(isdoor(m[nxt.row][nxt.col]) && (nxt.keys & keybin(m[nxt.row][nxt.col])) == 0)) continue;
			nxt.keys |= keybin(m[nxt.row][nxt.col]);
			q.push(nxt);
		}
	}

	cout << "--" << endl;
	return 0;
}