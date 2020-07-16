#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int cnt = ceil(a/(double)b);
	
	char letter;
	for (int i = 0; i < n; ++i) {
		int rnd = i%a;

		if (rnd == 0 || (i%a) % b == 0)
			letter = 'a';

		cout << letter++;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    while (TC--)
    	solve();
	return 0;
}