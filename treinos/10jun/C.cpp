#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 112345;

int up[MxN], down[MxN], turn[MxN];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int N, T;
    cin >> N >> T;

    for (int i = 0; i < N; ++i) {
    	cin >> up[i];
    }

    for (int i = 0; i < N; ++i) {
    	cin >> down[i];
    }

    while (T--) {
    	int i, j;
    	cin >> i >> j;
    	turn[i-1] = !turn[i-1];
    	turn[j] = !turn[j];
    }

    bool turned = false;
    for (int i = 0; i < N; ++i) {
    	turned ^= turn[i];
    	if (turned)
    		cout << down[i] << ' ';
    	else
    		cout << up[i] << ' ';
    }
    cout << endl;
	return 0;
}