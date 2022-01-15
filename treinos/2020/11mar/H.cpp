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
    	string line;
    	cin.ignore();
    	getline(cin, line);
    	unordered_set<char> uset;
    	for (char c : line) {
    		if (c >= 'a' && c <= 'z')
    			uset.insert(c);
    	}

    	// cout << uset.size();
    	if (uset.size() == 26)
    		cout << "frase completa" << endl;
    	else if (uset.size() >= 13)
    		cout << "frase quase completa" << endl;
    	else
    		cout << "frase mal elaborada" << endl;
    }
	return 0;
}