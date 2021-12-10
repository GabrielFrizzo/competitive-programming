#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int MxN = 35;
int v[MxN], vv[MxN];
int N, done;

void flip(int j) {
	for (int i = 1; i <= (N-j)/2+1; ++i)
	{
		swap(v[i], v[N-j-i+2]);
	}
	cout << j << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	string line;
	while(getline(cin, line)) {
		stringstream ss(line);

		N = 1;
		while (ss >> vv[N]) {
			N++;
		}
		N--;
		for (int i = 1; i < N; ++i) {
			cout << vv[i] << ' ';
		}
		cout << vv[N] << endl;

		for (int i = 1; i <= N; ++i)
		{
			int menor = 9999;
			int pmenor = -1;
			for (int j = 1; j <= N; ++j)
			{
				if (vv[j] < menor) {
					pmenor = j;
					menor = vv[j];
				}
			}
			v[pmenor] = i;
			vv[pmenor] = 9999;
		}

		// for (int i = 1; i < N; ++i) {
		// 	cout << v[i] << ' ';
		// }
		// cout << v[N] << endl;

		for (done = N; done >= 1; --done) {
			bool flag = false;
			for (int j = 1; j <= N; ++j) if (v[j] != j) flag = true;
			if (!flag) break;
			for (int j = 1; j < done; ++j) {
				flag = false;
				for (int jj = 1; jj <= N; ++jj) if (v[jj] != jj) flag = true;
				if (!flag) break;
				if (v[j] == done) {
					if (j != 1)
						flip(N-j+1);
					// for (int asd = 1; asd <= N; ++asd) cout << v[asd] << ' ';
					// cout << 'a' << endl;
					if (done != 1)
						flip(N-done+1);
					// for (int asd = 1; asd <= N; ++asd) cout << v[asd] << ' ';
					// cout << 'b' << endl;
					// cout << endl;
					break;
				}
			}
		}

		cout << 0 << endl;
	}

	return 0;
}