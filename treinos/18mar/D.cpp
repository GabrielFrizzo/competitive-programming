#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, inp, total = 0, spare = 0;
    cin >> n >> m;

    while (n--) {
    	cin >> inp;
    	int diff = inp - m - spare;
    	total += abs(diff);
    	spare = diff;
    }


    cout << total << endl;

	return 0;
}