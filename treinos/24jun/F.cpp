#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112345;

int v[MxN];
int M;

int testa(int mid) {

	ll l = 0, h = 0;
	for (int i = 0; i < M; ++i) {
		if (v[i] < mid) l += v[i];
		else if (v[i] > mid) h += v[i];
	}

	// cout << mid << ' ' << l << ' ' << h << endl;
	if (l > h) return -1;
	return (l!=h);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;

    int low = 0, hi = 21234;
    for (int i = 0; i < M; ++i) {
    	cin  >> v[i];
    	low = min(low, v[i]);
    	hi = max(hi, v[i]);
    }

    int ans = low;
    while (low < hi) {
    	int mid = low + (hi-low)/2;

    	int t = testa(mid);
    	if (t == 1) {
    		low = mid+1;
    	} else if (t == -1) {
    		hi = mid;
    	} else {
    		ans = mid;
    		hi = mid;
    	}
    }

    cout << ans << endl;

	return 0;
}