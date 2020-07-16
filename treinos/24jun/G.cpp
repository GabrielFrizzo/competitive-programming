#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

double fac(int i) {
	if (i == 1) return 0;
	return log10(i) + fac(i-1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p;
    cin >> p;
    int inp;
    cin >> inp;
    const double log365 = log10(365);
    double ans = -log365*(inp-1);
    int gone = inp;
    for(int i = 1; i < p; ++i) {
    	cin >> inp;
    	ans += log10(365-i) - log365*inp;
    	gone += inp;
    }

    cout << ans+fac(7)-fac(5) << endl;
	return 0;
}

// 7
// 1  1  			2			  	1				  3			  1			  1
// 1  364/365	(363/365)*1/365

// 1.94082e-08
// -7.71202
