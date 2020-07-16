#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    multiset<int> mset;
    for (int i = 0; i < n; ++i) {
    	int inp;
    	cin >> inp;
    	mset.insert(inp);
    }

    for (int i = 0; i < q; ++i) {
    	int inp;
    	cin >> inp;
    	if (inp > 0) {
    		mset.insert(inp);
    	} else {
    		multiset<int>::iterator it = mset.begin();
    		// cout << inp << endl;
    		advance(it, -inp-1);
    		mset.erase(it);
    	}
    }

    if (mset.empty()) {
    	cout << 0 << endl;
    } else {
    	cout << *mset.begin() << endl;
    }

	return 0;
}