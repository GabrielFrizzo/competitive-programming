#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vi v(N);

    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    }
    sort(v.begin(), v.end());
    v.push_back(v[0]+24);

    int best1 = 0, best2 = 0;

    for (int i = 1; i < N; i+=2) {
    	best1 += min(v[i]-v[i-1], 24-v[i]+v[i-1]);
    	best2 += min(v[i+1]-v[i], 24-v[i+1]+v[i]);
    	// cout << best1 << " " << best2 << endl;
    }

    cout << min(best1, best2) << endl;

	return 0;
}