#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int rafael(int x , int y) {
	return (3*x)*(3*x)+y*y;
}

int beto(int x , int y) {
	return 2*(x*x)+(5*y)*(5*y);
}

int carlos(int x , int y) {
	return -100*x+y*y*y;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
    	int x, y;
    	cin >> x >> y;
    	int b = beto(x, y);
    	int c = carlos(x, y);
    	int r = rafael(x, y);

    	if (b > c) {
    		if (b > r)
    			cout << "Beto";
    		else cout << "Rafael";
    	} else {
    		if (c > r)
    			cout << "Carlos";
    		else cout << "Rafael";
    	}

    	cout << " ganhou" << endl;
    }
	return 0;
}