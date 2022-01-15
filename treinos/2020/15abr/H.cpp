#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a;
    cin >> b;

    for (char &c : a)
    	c = tolower(c);

    for (char &c : b)
    	c = tolower(c);

    if (a < b)
    	cout << -1 << endl;
    else if (a == b)
    	cout << 0 << endl;
    else
    	cout << 1 << endl;
	return 0;
}