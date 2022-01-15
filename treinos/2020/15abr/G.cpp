#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int N;
char m[8][8];

vector<pii> directions = {{0,1}, {0,-1}, {1,-1}, {1,1}, {-1,-1}, {-1,1}, {1,0}, {-1,0}};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < 8 && j < 8;
}

bool mark(int i, int j) {
	if (!valid(i, j)) return true;
	if (m[i][j] < 2) {
		m[i][j] = 1;
		return false;
	}
	if (m[i][j] >= 2) {
		m[i][j] = 3;
		return true;
	}
	return true;
}

void peao(int col, int row) {
	mark(row-1, col-1);
	mark(row-1, col+1);
}

void bispo(int col, int row) {
	for (int i = 1; i <= 8; ++i) {
		if (mark(row+i, col+i)) break;
	}
	for (int i = 1; i <= 8; ++i) {
		if (mark(row-i, col+i)) break;
	}
	for (int i = 1; i <= 8; ++i) {
		if (mark(row-i, col-i)) break;
	}
	for (int i = 1; i <= 8; ++i) {
		if (mark(row+i, col-i)) break;
	}
}

void torr(int col, int row) {
	for (int i = 1; i <= 8; ++i) {
		if (mark(row+i, col)) break;
	}
	for (int i = 1; i <= 8; ++i) {	
		if (mark(row-i, col)) break;
	}
	for (int i = 1; i <= 8; ++i) {	
		if (mark(row, col-i)) break;
	}
	for (int i = 1; i <= 8; ++i) {	
		if (mark(row, col+i)) break;
	}
}

void rei(int col, int row) {
	for (pii d : directions) {
		mark(row+d.first, col+d.second);
	}
}

char pcs[123];
int rows[123], cols[123];

void solve() {
	memset(m, 0, sizeof(m));

	char pc, c; int row;
	for (int i = 0; i < N; ++i) {
		scanf(" %c %c %d", &pc, &c, &row);
		int col = c - 'a'; row--;
		pcs[i] = pc; cols[i] = col; rows[i] = row;
		m[row][col] = 2;
	}

	// for (int i = 0; i < 8; ++i) {
	// 	for (int j = 0; j < 8; ++j) {
	// 		cout << (int)m[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	for (int i = 0; i < N; ++i) {
		if (pcs[i] == 'P') peao(cols[i], rows[i]);
		else if (pcs[i] == 'T') torr(cols[i], rows[i]);
		else if (pcs[i] == 'B') bispo(cols[i], rows[i]);
		else if (pcs[i] == 'R') bispo(cols[i], rows[i]), torr(cols[i], rows[i]);
		else if (pcs[i] == 'W') rei(cols[i], rows[i]);
	}

	scanf(" %c %c %d", &pc, &c, &row);
	int col = c - 'a'; row--;

	// for (int i = 0; i < 8; ++i) {
	// 	for (int j = 0; j < 8; ++j) {
	// 		cout << (int)m[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	if (m[row][col]) {
		for (pii d : directions) {
			int ni = row+d.first, nj = col+d.second;
			if (valid(ni, nj) && (m[ni][nj] == 0 || m[ni][nj] == 2)) {
				cout << "NAO" << endl;
				return;
			}
		}
		cout << "SIM" << endl;
		return;
	}

	cout << "NAO" << endl;
	return;
}


int main() {
	while (scanf("%d", &N) != EOF) {
		solve();
	}

	return 0;
}