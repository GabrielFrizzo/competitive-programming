#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int M, T;

int notetoi(string note) {
	int ans;
	if (note[0] == 'A') ans = 1;
	else if (note[0] == 'B') ans = 3;
	else if (note[0] == 'C') ans = 4;
	else if (note[0] == 'D') ans = 6;
	else if (note[0] == 'E') ans = 8;
	else if (note[0] == 'F') ans = 9;
	else if (note[0] == 'G') ans = 11;

	if (note.size() == 2) {
		if (note[1] == '#') ans++;
		else ans--;
	}

	return ans;
}

void solve() {
	vi a, b;

	for (int i = 0; i < M; ++i) {
		string inp;
		cin >> inp;
		a.push_back(notetoi(inp));
	}

	for (int i = 0; i < T; ++i) {
		string inp;
		cin >> inp;
		b.push_back(notetoi(inp));
	}

	vi adiff, bdiff;
	for (int i = 1; i < M; ++i) {
		adiff.push_back(((a[i]-a[i-1])+12)%12);
	}

	for (int i = 1; i < T; ++i) {
		bdiff.push_back(((b[i]-b[i-1])+12)%12);
	}

	// for (int i : adiff) cout << i << ' ';
	// cout << endl;
	// for (int i : bdiff) cout << i << ' ';
	// cout << endl;
	vi back;
	back.push_back(-1);
	int curr = -1;
	for (int i = 1; i < (int)bdiff.size(); ++i) {
		while(curr >= 0 && bdiff[i] != bdiff[curr]) curr = back[curr];
		back.push_back(++curr);
	}

	curr = 0;
	for (int i = 0; i < (int)adiff.size(); ++i) {
		while(curr >= 0 && adiff[i] != bdiff[curr]) curr = back[curr];
		curr++;
		if (curr == (int)bdiff.size()) {
			cout << 'S' << endl;
			return;
		}
	}

	cout << 'N' << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> M >> T, M) {
    	solve();
    }
	return 0;
}