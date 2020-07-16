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
    	int N;
    	cin >> N;
    	while (N--) {
    		int i;
    		string res;
    		cin >> i;
    		if (i == 1) res = "Rolien";
    		if (i == 2) res = "Naej";
    		if (i == 3) res = "Elehcim";
    		if (i == 4) res = "Odranoel";
    		cout << res << endl;
    	}
    }
	return 0;
}