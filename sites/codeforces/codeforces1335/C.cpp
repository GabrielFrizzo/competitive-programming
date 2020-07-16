#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, found = -1, inp, best = 0;
	cin >> n;

	unordered_map<int, int> umap;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		umap[inp]++;
	}

	for (auto p : umap) {
		best = max(best, p.second);
	}

	int r = best;
	int l = umap.size()-1;
	if (r-1 >= l+1) return l+1;
	return min(r, l);
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while (TC--)
    	cout << solve() << endl;

	return 0;
}