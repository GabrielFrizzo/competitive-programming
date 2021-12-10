#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 1123456;
const int MOD = 1e9 + 7;


void no() {
	cout << "N" << endl;
}

bool v[MxN];

void upd(int i) {
	if (v[i]) {
		v[i] = false;
		upd(i+1);
	} else {
		v[i] = true;
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int inp;
		cin >> inp;
		upd(inp);
	}

	if (N == 1) {
		cout << "N" << endl;
	} else  {
		int total = 0;
		for (int i = 0; i < MxN; ++i)
		{
			total += v[i];
		}

		if (total <= 2) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
	}
	
	return 0;
}