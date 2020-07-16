#include <bits/stdc++.h>
using namespace std;

#define MxN 11234

int cnts[MxN];

void solve(int r, int k) {
	memset(cnts, 0, sizeof(cnts));
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		cnts[a]++;
		cnts[b]++;
	}
    unordered_set<int> cansum;
    cansum.clear();
    cansum.insert(0);
    for (int i = 0; i < r; ++i) {
        for (int j = k; j >= cnts[i]; --j) {
            if (cansum.count(j-cnts[i])) {
                cansum.insert(j);
            }
        }
    }

    cout << (cansum.count(k) == 1 ? "S" : "N") << endl;

}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, k;
    
    while (cin >> r >> k) {
    	solve(r, k);
    }

	return 0;
}