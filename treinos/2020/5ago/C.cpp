#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		int total = 0;
		for (int i = 1; i <= a; ++i) {
			int inp;
			cin >> inp;
			if (inp&1)
				total ^= i;
		}
		if (total) {
			cout << "Tom Wins" << endl;
		} else {
			cout << "Hanks Wins" << endl;
		}
	}
	return 0;
}