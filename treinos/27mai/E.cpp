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

    ll total = 0;
    vi v(N);
    for (int i = 0; i < N; ++i) {
    	cin >> v[i];
    	total += v[i];
    }
    if (total&1){
    	cout << "N" << endl;
    	return 0;
    }

    ll aim = total/2;
    ll diagonal = v[0];
    bool good = false;
    int i = 0, j = 1;
    while (j < N) {
    	if (diagonal < aim) {
    		diagonal += v[j++];
    	} else if (diagonal > aim) {
    		diagonal -= v[i++];
    	} else {
    		good = true;
    		break;
    	}
    }

    if (!good) {
    	cout << "N" << endl;
    	return 0;
    }

    good = false;
    diagonal = v[0];
    int i2 = 0, j2 = 1;
    while (j2 < N) {
    	if (diagonal < aim || j2 == j || j2 == i) {
    		diagonal += v[j2++];
    	} else if (diagonal > aim || i2 == j || i2 == i) {
    		diagonal -= v[i2++];
    	} else {
    		good = true;
    		break;
    	}
    }

    if (!good) {
    	cout << "N" << endl;
    	return 0;
    }
    cout << "Y" << endl;

	return 0;
}
