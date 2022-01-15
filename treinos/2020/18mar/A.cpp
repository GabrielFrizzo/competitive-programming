#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, inp;

    cin >> n >> m;

    map<int,int> houses;

    for (int i= 0 ; i < n; i++) {
    	cin >> inp;
    	houses.insert(make_pair(inp, i));
    }

    int curr = 0, total = 0;

    for (int i = 0; i < m; i++) {
    	cin >> inp;
    	total += abs(houses[inp] - curr);
    	curr = houses[inp];
    }

    cout << total << endl;
	return 0;
}