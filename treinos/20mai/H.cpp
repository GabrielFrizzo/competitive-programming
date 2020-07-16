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
    ll total = 0, stars = 0, ones = 0;
    bool flag = false;
    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    	if (!flag) {
			if (v[i]&1) {
				ones += v[i] == 1;
				total += max(v[i]-2, 0);
				stars++;
			} else {
				total += v[i]-1;
				stars++;
				flag = true;
			}
		} else {
			total += v[i];
		}
    }
    if (!flag) total+=N-ones;

    cout << stars << ' ' << total << endl; 
	return 0;
}