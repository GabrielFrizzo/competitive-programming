#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
	string line;
	cin >> line;
	int nums[] = {-1,-1,-1,-1};
	int best = 1e9;
	for (int i = 0; i < line.size(); ++i) {
		int num = line[i]-'0';
		nums[num] = i;
		if (nums[1] != -1 && nums[2] != -1 && nums[3] != -1) {
			int ans = i+1 - min(nums[1], min(nums[2], nums[3]));
			best = min(ans, best);
		}
	}
	cout << (best == 1e9 ? 0 : best) << endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
    	solve();
    }
	return 0;
}