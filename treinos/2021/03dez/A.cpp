#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
using pcsi = pair<char, pair<string, int>>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

string line;

bool isMaj(char c) {
	return c >= 'A' && c <= 'Z';
}

char get(int i) {
	if (i < 0 || i >= line.size()) return 0;
	return line[i];
}

pcsi getMajWord(int i) {
	string ret;
	ret += get(i);
	char letter = 0;
	int j = i+1;
	if (!isalpha(get(i))) return {letter, {ret, j}};
	if (isMaj(get(i))) letter = get(i);

	while(isalpha(get(j))) {
		ret += get(j);
		if (isMaj(get(j))) letter = 0;
		j++;
	}

	// cerr << letter << ':' << ret << ':' << j << endl;
	if (j == i+1) letter = 0;
	return {letter, {ret, j}};
}

void printStrings(vector<string>& strings) {
	for(int i = 0; i < strings.size(); ++i) {
		if (i != 0) cout << ' ';
		cout << strings[i];
	}
}

void flush(string &acronym, vector<string> &words, bool putSpace) {
	if (acronym.size() >= 2) {
		cout << acronym << " (";
		printStrings(words);
		cout << ')';
		if (putSpace) cout << ' ';
	} else if (acronym.size() == 1) {
		cout << words[0];
		if (putSpace) cout << ' ';
	}
	acronym = "";
	words.clear();
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	while (getline(cin, line)) {
		int N = line.size();
		vector<string> words;
		string acronym = "";
		bool expectSpace = false;
		for(int i = 0; i <= N;) {
			if (expectSpace) {
				if (get(i) != ' ') {
					flush(acronym, words, false);
					if (get(i))
						cout << get(i);
				}
				expectSpace = false;
				i++;
				continue;
			}
			pcsi curr = getMajWord(i);
			i = curr.second.second;
			if (curr.first == 0) {
				flush(acronym, words, true);
				for(char c : curr.second.first)
					if (c) cout << c;
			} else {
				acronym += curr.first;
				words.push_back(curr.second.first);
				expectSpace = true;
			}
		}
		cout << endl;
	}

	return 0;
}