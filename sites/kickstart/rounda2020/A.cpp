#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int solve() {
	int N, B;
	cin >> N >> B;

	vi houses;
	while (N--) {
		int inp;
		cin >> inp;
		houses.push_back(inp);
	}

	sort(houses.begin(), houses.end());

	for (int i = 0; i < houses.size(); ++i) {
		if (houses[i] > B) return i;
		B-=houses[i];
	}
	return houses.size();
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	cout << "Case #" << i << ": ";
    	cout << solve() << endl;
    }
	return 0;
}