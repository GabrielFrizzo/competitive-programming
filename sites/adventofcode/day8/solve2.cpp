#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

/*
	2 -> [1]
	3 -> [7]
	4 -> [4]
	5 -> [2,3,5]
	6 -> [0,6,9]
	7 -> [8]
*/

/*
	1,4,7,8 dados
	3 = 5seg contem 1
	b = 4 - 3
	5 = 5seg contem b
	2 = 5seg restante
	6 = 6seg nao contem 1
	9 = 6seg contem 5
	0 = 6seg restante
*/

bool contains(const string &a, const char c) {
	for(char aa : a) if (c == aa) return true;
	return false;
}

bool contains(const string &a, const string &b) {
	for(char bb : b) {
		if (!contains(a, bb)) return false;
	}
	return true;
}

char difference(const string &a, const string &b) {
	for(char aa : a) {
		if (!contains(b, aa)) return aa;
	}
}

int solve() {
	string inp[10];
	bool done[10];
	memset(done, 0, sizeof done);
	char pipe;
	for(int i = 0; i < 10; ++i) {
		cin >> inp[i];
		sort(inp[i].begin(), inp[i].end());
	}
	cin >> pipe;

	int posInInp[10];
	memset(posInInp, -1, sizeof posInInp);

	// 1,4,7,8 dados
	for(int i = 0; i < 10; ++i) {
		if (inp[i].size() == 2) { posInInp[1] = i;done[i] = true; }
		else if (inp[i].size() == 3) { posInInp[7] = i;done[i] = true; }
		else if (inp[i].size() == 4) { posInInp[4] = i;done[i] = true; }
		else if (inp[i].size() == 7) { posInInp[8] = i;done[i] = true; }
	}

	// 3 = 5seg contem 1
	for(int i = 0; i < 10; ++i) {
		if (inp[i].size() == 5 && contains(inp[i], inp[posInInp[1]])) {
			posInInp[3] = i;
			done[i] = true;
			break;
		}
	}

	// b = 4 - 3
	char b = difference(inp[posInInp[4]], inp[posInInp[3]]);

	// 5 = 5seg contem b
	for(int i = 0; i < 10; ++i) {
		if (inp[i].size() == 5) {
			for(char c : inp[i]) {
				if (c == b) { posInInp[5] = i;done[i] = true; }
			}
		}
	}

	// 2 = 5seg restante
	for(int i = 0; i < 10; ++i) {
		if (inp[i].size() == 5 && !done[i]) {
			posInInp[2] = i;
			done[i] = true;
			break;
		}
	}

	// 6 = 6seg nao contem 1
	for(int i = 0; i < 10; ++i) {
		if (inp[i].size() == 6 && !contains(inp[i], inp[posInInp[1]])) {
			cout << "found 6!" << i << endl;
			posInInp[6] = i;
			done[i] = true;
			break;
		}
	}

	// 9 = 6seg contem 5
	for(int i = 0; i < 10; ++i) {
		if (!done[i] && inp[i].size() == 6 && contains(inp[i], inp[posInInp[5]])) {
			cout << "found 9!" << i << endl;
			posInInp[9] = i;
			done[i] = true;
			break;
		}
	}

	// 0 = 6seg restante
	for(int i = 0; i < 10; ++i) {
		if (inp[i].size() == 6 && !done[i]) {
			posInInp[0] = i;
			done[i] = true;
			break;
		}
	}

	for(int i = 0; i < 10; ++i) {
		if (!done[i])
			cout << "not done" << ' ' << inp[i] << endl;
		
		cout << i << ' ' << posInInp[i] << endl;
	}

	int total = 0;
	for(int i = 3; i >= 0; --i) {
		string out;
		cin >> out;
		sort(out.begin(), out.end());
		for(int j = 0; j < 10; ++j) {
			if (inp[posInInp[j]] == out) {
				total += int(pow(10,i))*j;
			}
		}
	}

	cout << total << endl;
	return total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int total = 0;
	while (N--) {
		total += solve();
	}

	cout << total << endl;

	return 0;
}