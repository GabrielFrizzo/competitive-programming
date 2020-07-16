// HaHa3.5 - Longest Increasing Subsequence (LIS)

#include <bits/stdc++.h>
using namespace std;

#define MAX 1<<20

vector<int> v;
int lis[MAX];

void solve() {
	int res = 1;
	lis[0] = 1;
	for (int i = 1; i < v.size(); i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] <= v[j]) {
				lis[i] = max(lis[i], lis[j] + 1);
				res = max(res, lis[i]);

			}
		}
	}

	cout << res;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int inp = 0, TC = 1;

    cin >> inp;
    while (inp != -1) {
    	v.clear();
    	while (inp != -1) {
    		v.push_back(inp);
    		cin >> inp;
    	}
    	cout << "Test #" << TC++ << ":" << endl;
    	cout << "  maximum possible interceptions: ";
    	solve();
    	cout << endl;
    	cin >> inp;
    	if (inp != -1)
    		cout << endl;
	}
    
	return 0;
}

// 389
// 207
// 155
// 300
// 299
// 170
// 158
// 65
// -1
// 23
// 34
// 21
// -1
// -1
