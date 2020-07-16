#include <bits/stdc++.h>
using namespace std;

#define MxN 1123

int m[MxN][MxN];
int side[MxN];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		cin >> m[i][j];
    	}
    }
    memset(side, -1, sizeof(side));
    queue<int> q; q.push(0);
    side[0] = 0;
    bool res = true;
	while (!q.empty() && res) {
		int curr = q.front(); q.pop();
		for (int nxt = 0; nxt < N; nxt++) {
			if (m[curr][nxt] == 0) {
				if (side[nxt] == -1) {
					side[nxt] = !side[curr];
					q.push(nxt);
				} else if (side[curr] == side[nxt]) {
				 cout << "Fail!" << endl;
				 exit(0);
				}
			}
		}
	}

    cout << "Bazinga!" << endl;

	return 0;
}