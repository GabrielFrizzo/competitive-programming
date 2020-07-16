#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 512;

int N, M;
char m[MxN][MxN];

void dfs(int i, int j) {
	m[i][j] = 'o';
	if (m[i+1][j] == '.') {
		dfs(i+1, j);
	}
	else if (m[i+1][j] == '#') {
		if (m[i][j+1] == '.')
			dfs(i, j+1);
		if (m[i][j-1] == '.')
			dfs(i, j-1);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &N, &M);
	pii pos;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &m[i][j]);
			if (m[i][j] == 'o')
				pos = {i, j};
		}
	}

	dfs(pos.first, pos.second);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			printf("%c", m[i][j]);
		}
		printf("\n");
	}

	return 0;
}