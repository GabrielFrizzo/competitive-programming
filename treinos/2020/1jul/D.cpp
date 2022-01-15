#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int MxN = 1123;

int v[MxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, I, F;
    cin >> N >> I >> F;
    int res = 0;

    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    }

    for (int i = 0; i < N; ++i) {
    	for (int j = i+1; j < N; ++j) {
    		int aux = v[i] + v[j];
    		res += aux >= I && aux <= F;
    	}
    }

    cout << res << endl;
	return 0;
}