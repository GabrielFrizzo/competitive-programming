#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<int,int>;
using pci = pair<char, int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;
const vector<char> openers = {'[', '(', '<', '{'};
const vector<pci> closers = {{']', 57}, {')', 3}, {'>', 25137}, {'}', 1197}};

const int ctoi(const char c) {
	if (c == '[' || c == ']') return 0;
	if (c == '(' || c == ')') return 1;
	if (c == '<' || c == '>') return 2;
	return 3;
}

const int points(const char c) {
	if (c == '[' || c == ']') return 2;
	if (c == '(' || c == ')') return 1;
	if (c == '<' || c == '>') return 4;
	return 3;
}

ll solve() {
	string line;
	cin >> line;
	stack<char> q;
	for(char c : line) {
		if (find(openers.begin(), openers.end(), c) != openers.end()) {
			q.push(c);
		} else {
			if (q.top() != openers[ctoi(c)]) return -1;
			q.pop();
		}
	}

	ll total = 0;
	while (!q.empty()) {
		total *= 5;
		total += points(q.top());
		q.pop();
	}

	return total;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vi scores;
	while (N--) {
		ll s = solve();
		if (s != -1) scores.push_back(s);
	}
	sort(scores.begin(), scores.end());
	cout << scores[scores.size()/2] << endl;

	return 0;
}