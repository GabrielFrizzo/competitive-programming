#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, inp, total = 0;
    cin >> x;

    while (cin >> inp)
    	total += inp == x;

    cout << total << endl;
	return 0;
}