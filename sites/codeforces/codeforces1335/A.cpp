#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    int inp;
    while(T--) {
    	cin >> inp;
    	cout << inp-inp/2-1 << endl;
    }
	return 0;
}