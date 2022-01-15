#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    vi v(H);
    for (int i = 0; i < H; ++i) {
    	cin >> v[i];
    }

    int best = 0;;
    for (int i = 0; i < H; ++i) {
    	int inp;
    	cin >> inp;
    	best = max(best, inp+v[i]);
    }

    cout << (W-best)/2. << endl;

	return 0;
}