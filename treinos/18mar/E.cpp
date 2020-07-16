#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, curr = -1, inp;

    cin >> n >> m;

    while (n--) {
    	int end0 = 0;
    	for (int i= 0; i < m; i++) {
    		cin >> inp;
    		if (!end0 && inp != 0) {
    			if (curr >= i) {
    				cout << "N" << endl;
    				exit(0);
    			}
    			curr = i;
    			end0 = 1;
    		}
    	}
    	if (end0 == 0) {
    		curr = m;
    	}
    }

    cout << "S" << endl;
	return 0;
}