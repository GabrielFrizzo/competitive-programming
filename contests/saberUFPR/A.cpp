#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int a = N/365;
	int m = (N - a*365)/30;
	int d = (N - a*365 - m*30);

	cout << a << " ano(s)" << endl;
	cout << m << " mes(es)" << endl;
	cout << d << " dia(s)" << endl;
	return 0;
}