#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i < n; i++) {
		if (n%i == 0) {
			cout << i << n/i << endl;
			return 0;
		}
	}    
	return 0;
}

