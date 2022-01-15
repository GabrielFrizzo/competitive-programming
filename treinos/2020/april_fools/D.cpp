#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c[6];
    int c7;
    for (int i = 0; i < 6; i++) {
    	cin >> c[i]; 
    }

    cin >> c7;
    cout << c7%2 << endl;
	return 0;
}