#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, res = 0;

    cin >> n;
	// 164352
	// 502314
    res |= (n%2) << 4;
    n >>= 1;
    res |= (n%2) << 1;
    n >>= 1;
    res |= (n%2) << 3;
    n >>= 1;
    res |= (n%2) << 2;
    n >>= 1;
    res |= (n%2) << 0;
    n >>= 1;
    res |= (n%2) << 5;

    cout << res << endl;
	return 0;
}
