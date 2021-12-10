#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string inp;
	cin >> inp;

	int points[2] = {0, 0}, games[2] = {0, 0};
	int winner = 0;
	int server = 0;

	for (char c : inp) {
		if (c == 'S' || c == 'R') {
			if (winner) continue;
			int pointer = c == 'S' ? server : !server;
			points[pointer]++;
			server = pointer;
			if (points[pointer] == 10 || (points[pointer] >=5 && points[pointer] >= points[!pointer] + 2)) {
				points[0] = points[1] = 0;
				games[pointer]++;
				if (games[pointer] == 2) {
					winner = pointer + 1;
				}
			}
		} else {
			if (winner == 1) {
				cout << games[0] << " (winner) - " << games[1];
			} else if (winner == 2) {
				cout << games[0] << " - " << games[1] << " (winner)";
			} else {
				cout << games[0] << " (" << points[0];
				if (!server) cout << '*';
				cout << ") - " << games[1] << " (" << points[1];
				if (server) cout << '*';
				cout << ")";
			}
			cout << endl;
		}
	}

	return 0;
}