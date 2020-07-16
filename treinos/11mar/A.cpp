#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
    int TC;
    cin >> TC;
    while (TC--) {
    	string inp, base;
    	int N;
    	cin >> N;
    	cin >> base;
    	N--;
    	while (N--) {
    		cin >> inp;
    		if (inp != base)
    			base = "ingles";
    	}
    	cout << base << endl;
    }
	return 0;
}