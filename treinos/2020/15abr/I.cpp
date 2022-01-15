#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    int center = n/2;
    if ((x == center || x == center+1) && (y == center || y == center+1)){
    	cout << "NO" << endl;
    	return 0;
    }
    cout << "YES" << endl;

	return 0;
}