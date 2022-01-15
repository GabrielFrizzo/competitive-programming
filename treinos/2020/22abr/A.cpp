#include <bits/stdc++.h>
using namespace std;

unordered_set<string> uset;

int solve() {
	string s;
	cin >> s;

	int ppos = s.find('+');
	int atpos = s.find('@');

	string parsed = "";
	if (ppos == string::npos)
		ppos = atpos;
	ppos--;

	string start = s.substr(0,ppos);
	for (char c : start) {
		if (c != '.')
			parsed += c;
	}
	parsed += s.substr(atpos, s.size());
	if (uset.find(parsed) != uset.end())
		return 0;
	uset.insert(parsed);
	return 1;
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, res = 0;
    cin >> N;
    while (N--) {
    	res += solve();
    }

    cout << res << endl;
	return 0;
}