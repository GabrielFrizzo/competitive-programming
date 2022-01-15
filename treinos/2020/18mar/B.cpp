#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3;

 	int inp, curr = -1, order, res = 2;

 	cin >> inp;
 	cin >> curr;

 	order = curr > inp;
    while (n--) {
    	cin >> inp;
    	if (res == 2) {
	    	if (order && inp < curr) {
	    		res = 0;
	    	} else if (!order && inp > curr) {
	    		res = 0;
	    	}
    	}
    	curr = inp;
    }

    if (res == 0) {
    	cout << "N" << endl;
    } else {
    	if (order) {
    		cout << "C" << endl;
    	} else {
    		cout << "D" << endl;
    	}
    }
	return 0;
}