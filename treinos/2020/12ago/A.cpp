#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;

	while(cin >> N)
		{int best = 0;
		while(N--) {
			int inp;
			cin >> inp;
			best = max(best, inp);
		}
	
		if (best < 10) {
			cout << 1;
		} else if (best < 20) {
			cout << 2;
		} else {
			cout << 3;
		}
	
		cout << endl;}
	return 0;
}