#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

void solve() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	// cout << line;
	vector<string> v;
	string word;
	while(ss >> word) {
		v.push_back(word);
	}

	// for (string s: v)
		// cout << s << ' ';
	while(getline(cin, line), line != "what does the fox say?") {
		string a, b, c;
		stringstream dd(line);
		dd >> a >> b >> c;
		for (string& s : v)
			if (s == c)
				s = "";
	}

	for (string s: v)
		if (s != "")
			cout << s << ' ';

	cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
	cin.ignore();
    
    while (TC--) {
    	solve();
    }
	return 0;
}