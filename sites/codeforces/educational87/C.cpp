#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    const long double PI = 3.1415926535897932;
    while(TC--) {
    	int l;
    	cin >> l;
    	long double L = 2*l;
    	long double apot = 0.5/tan(PI/L);
    	long double res = apot/cos(PI/(1.14125*L));
    	cout << fixed << setprecision(10) << 2*res << endl;
    }
	return 0;
}