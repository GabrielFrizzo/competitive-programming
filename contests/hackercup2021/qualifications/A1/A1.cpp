#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

int counts[26];

bool isvowel(char a) {
	if (a == 'A') return true;
	if (a == 'E') return true;
	if (a == 'I') return true;
	if (a == 'O') return true;
	if (a == 'U') return true;
	return false;
}

void solve() {
	memset(counts, 0, sizeof(counts));
	string s;
	cin >> s;

	int vowels = 0;

	for (char c : s) {
		vowels += isvowel(c);
		counts[c-'A']++;
	}

	int consonants = s.length() - vowels;

	int top_vowel = 0, top_cons = 0;
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		if (isvowel(i)) {
			top_vowel = max(top_vowel, counts[i-'A']);
		} else {
			top_cons = max(top_cons, counts[i-'A']);
		}
	}

	int change_to_vowel = consonants + (vowels - top_vowel)*2;
	int change_to_cons  = vowels     + (consonants - top_cons)*2;

	cout << min(change_to_cons, change_to_vowel);
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}