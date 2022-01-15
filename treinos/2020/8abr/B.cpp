#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, t, f;

    cin >> s >> t >> f;

    cout << (s + t + f + 24) % 24 << endl;
	return 0;
}