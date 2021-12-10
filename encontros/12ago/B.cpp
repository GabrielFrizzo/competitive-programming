#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int INF = 1e9+7;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	while(cin >> N, N) {
		vector<string> inp(N);
		for (int i = 0; i < N; ++i) {
			cin >> inp[i];
		}

		sort(inp.begin(), inp.end());

		for (int i = 0; i < N-1; ++i) {
			if (inp[i+1].rfind(inp[i], 0) == 0) {
				cout << "Conjunto Ruim" << endl;
				goto label;
			}
		}
		cout << "Conjunto Bom" << endl;
label:
	int p;
	}


	return 0;
}