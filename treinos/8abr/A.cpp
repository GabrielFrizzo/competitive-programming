#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string inp;
    cin >> n >> m;

    while (m--) {
    	cin >> inp;

    	if (inp == "fechou")
    		n++;
    	else
    		n--;
    }

    cout << n << endl;
	return 0;
}