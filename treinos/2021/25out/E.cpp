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

	int N;
	map<int, int> m;
	int inp;
	cin >> N;
	while (N--) {
		cin >> inp;
		m[inp]++;
	}


	ll total = 0;
	for (pii a : m) {
		total += max(0, a.second-1);
	}


	cout << total << endl;
	return 0;
}