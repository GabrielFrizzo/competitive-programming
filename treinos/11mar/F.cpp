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
    while (TC--) {
    	int QT, S;
    	cin >> QT >> S;
    	int best = 1e9;
    	int besti;
    	for (int i = 1; i <= QT; ++i) {
    		int inp;
    		cin >> inp;
    		if (abs(inp-S) < best) {
    			best = abs(inp-S);
    			besti = i;
    		}
    	}

    	cout << besti << endl; 
    }
	return 0;
}