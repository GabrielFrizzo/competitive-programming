#include <bits/stdc++.h>

using namespace std;
const int MxN = 21234567;
bool v[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	int f, l;
	
	for (int i = 0; i < N; ++i) {
		string inp;
		cin >> inp;
		if (inp.size() <= 7) {
			int inpint = stoi(inp);
			if (inpint >= 0)
				v[inpint] = true;
		}
	}

	for (int i = 0; ; i++) {
		if (!v[i]) {
			cout << i << endl;
			break;
		}
	}
}

