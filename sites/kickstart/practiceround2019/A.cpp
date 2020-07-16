#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
    int A, B, N;
    cin >> A >> B >> N;
    int low = A+1, hi = B;
    int mid;
    while (true) {
    	mid = low + (hi-low)/2;

    	cout << mid << endl;
    	string resp;
    	cin >> resp;
    	if (resp == "TOO_SMALL")
    		low = mid+1;
    	else if (resp == "TOO_BIG")
    		hi = mid-1;
    	else
    		return;
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i) {
    	solve();
    }
	return 0;
}