#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

vector<int> freq;

pii findrep(ll inp) {
	freq.assign(10, 0);
	string line = to_string(inp);
	for (int i = 0; i < line.size(); ++i) {
		int c = line[i]-'0';
		if (freq[c]++ >= 2) {
			return {i, c};
		}
	}
	return {-1, -1};
}

ll trim(ll inp, int pos) {
	string line = to_string(inp);
	return stoll(line.substr(0, pos));
}

int next_free() {
	for (int i = 9; i >= 0; i--) {
		if (freq[i] < 2) return i;
	}
	assert(false);
}

ll leastvalid(ll inp) {
    int reppos, repn;
    while (true) {
    	// cout << inp << " ";
	    tie(reppos, repn) = findrep(inp);
	    // cout << reppos << endl;
	    if (reppos == -1) {
	    	return inp;
	    }

	    inp = trim(inp, reppos);
	    for (int i = repn-1; i >= 0; --i) {
	    	if (freq[i] < 2) {
	    		return inp*10 + i;
	    	}
	    }
	    inp--;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll inp;
    while(cin >> inp) {
		ll ans = leastvalid(inp), cand = ans;

		findrep(ans);
		while(cand <= inp) {
			ans = cand;
			int nxt = next_free();
			if (ans > ll(1e17)) break;
			cand = ans*10 + nxt;
			freq[nxt]++;
		}
		cout << ans << endl;
    }


	return 0;
}