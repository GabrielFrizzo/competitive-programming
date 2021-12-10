#include <bits/stdc++.h>
using namespace std;

const int MxN = 212;
const int MxK = MxN/2;

using vi = vector<int>;
string tri[MxN+12][MxN];

string soma_string(string& a, string& b) {
	int sa = a.size(), sb = b.size();
	int mm = max(sa, sb);
	vector<int> ans(mm+1);
	for (int i = 0; i < max(sa, sb); ++i) {
		if (sa-i-1 >= 0) ans[mm-i] += a[sa-i-1]-'0';
		if (sb-i-1 >= 0) ans[mm-i] += b[sb-i-1]-'0';
		if (ans[mm-i] > 9) {
			ans[mm-i] %= 10;
			ans[mm-i-1] += 1;
		}
	}

	string soma = "";
	bool start = true;
	for (int i : ans) {
		if (start && i==0) continue;
		soma += to_string(i);
		start = false;
	}

	return soma;
}


void triangulou() {
	for (int i = 0; i <= MxN; ++i) {
		tri[i][0] = tri[i][i] = "1";
		for (int j = 1; j < i; ++j) {
			tri[i][j] = soma_string(tri[i-1][j-1],tri[i-1][j]);
		}
	}

	// for (int i = 0; i <= 10; ++i) {
	// 	for (int j = 0; j <= i; ++j) {
	// 		cout << tri[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
}

void solve() {
	int N, K;
	cin >> N >> K;
	int total = 0;
	for (int i = 0; i < K; ++i) {
		int inp;
		cin >> inp;
		total += inp;
	}

	cout << tri[N-total+1][K] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < MxN; ++i)
		for (int j = 0; j < MxN; ++j)
			tri[i][j] = "0";
	triangulou();

	int N;
	cin >> N;
	while (N--) {
		solve();
	}


	return 0;
}



// resposeta:
// N - soma + 1 escolhe n_blocos
