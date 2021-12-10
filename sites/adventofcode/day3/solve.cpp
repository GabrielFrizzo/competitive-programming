#include <bits/stdc++.h>
using namespace std;

int count_[MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N = 0, M;

	string inp;
	while (cin >> inp) {
		N++;
		M = inp.size();
		for(int i = 0; i < M; ++i) {
			count_[i] += inp[i] == '1';			
		}
	}

	int final;
	for(int i = 0; i < M; ++i) {
		if (count_[i] >= N/2) final |= 1<<(M-i-1);
	}

	cout << final * (((1 << M) - 1) & ~final) << endl;
	

	return 0;
}