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

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cout << 'a';
	}
	for (int i = 0; i < n; ++i)
	{
		cout << 'b';
	}
	cout << endl;

	for (int i = 0; i < n-1; ++i)
	{
		cout << 'a';
	}
	cout << "ba";
	for (int i = 0; i < n-1; ++i)
	{
		cout << 'b';
	}
	cout << endl;

	return 0;
}