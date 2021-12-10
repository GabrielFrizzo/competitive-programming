#include <bits/stdc++.h>
using namespace std;

const int MxN = 112;
const int INF = 1e9;

	int N, M;
string m[MxN][MxN];
int lin[MxN], col[MxN];
map<string, int> smap;

void slv() {
	for (int i = 0; i < N; ++i) {
		string first = "";
		int total = 0;
		for (int j = 0; j < M; ++j) {
			if (smap[m[i][j]] == INF) {
				first = m[i][j];
				break;
			}
		}
		if (first != "") {
			int cnt = 0;
			bool good = true;
			for (int j = 0; j < M; ++j) {
				if (smap[m[i][j]] != INF) {
					total += smap[m[i][j]];
				} else if (first != m[i][j]) {
					good = false;
					break;
				} else {
					cnt++;
				}
			}
			if (good) {
				smap[first] = (col[i]-total)/cnt;
				// cout << (col[i]) << ' ' << total << ' ' << cnt << endl;
				// cout << first << 'a' << smap[first] << endl;
				return;
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		string first = "";
		int total = 0;
		for (int j = 0; j < N; ++j) {
			if (smap[m[j][i]] == INF) {
				first = m[j][i];
				break;
			}
		}
		if (first != "") {
			int cnt = 0;
			bool good = true;
			for (int j = 0; j < N; ++j) {
				if (smap[m[j][i]] != INF) {
					total += smap[m[j][i]];
				} else if (first != m[j][i]) {
					good = false;
					break;
				} else {
					cnt++;
				}
			}
			if (good) {
				smap[first] = (lin[i]-total)/cnt;
				// cout << first << 'b' << smap[first] << endl;
				return;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin.ignore();
		for (int j = 0; j < M; ++j) {
			cin >> m[i][j];
			smap[m[i][j]] = INF;
		}
		cin >> col[i];
	}

	for (int i = 0; i < M; ++i) {
		cin >> lin[i];
	}

	int lk = smap.size();
	while (lk--)
		slv();

	for (pair<string, int> p : smap) {
		cout << p.first << ' ' << p.second << endl;
	}

	return 0;
}