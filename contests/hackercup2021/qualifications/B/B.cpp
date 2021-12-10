#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 51;
const int INF = 1e8+5;
int vert[MxN], horz[MxN];
char mat[MxN][MxN];

void solve() {
	memset(vert, 0, sizeof(vert));
	memset(horz, 0, sizeof(horz));
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == 'O') {
				horz[i] = -1;
				vert[j] = -1;
			} else if (mat[i][j] == 'X') {
				horz[i] = horz[i] == -1 ? -1 : (horz[i] + 1);
				vert[j] = vert[j] == -1 ? -1 : (vert[j] + 1);
			}
		}
		cin.ignore();
	}

	int best = INF;
	int n_best = 0;
	for (int i = 0; i < N; ++i) {
		int vert_left = N - vert[i];
		int horz_left = N - horz[i];
		if (horz_left <= N && horz_left < best) {
			n_best = 1;
			best = horz_left;
		} else if (horz_left == best) {
			n_best++;
		}

		if (vert_left <= N && vert_left < best) {
			n_best = 1;
			best = vert_left;
		} else if (vert_left == best) {
			n_best++;
		}
	}

	if (best == 1)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (vert[i] == N-1 && horz[j] == N-1 && mat[i][j] == '.')
					n_best--;

	if (best == INF)
		cout << "Impossible";
	else
		cout << best << ' ' << n_best;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}