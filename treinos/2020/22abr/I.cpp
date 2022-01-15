#include <bits/stdc++.h>
using namespace std;

#define INS 0
#define DEL 1
#define REP 2
#define NOT 3
#define MxN 100

struct op {
	int id;
	int pos;
	char letter;
	op() {}
	op(int _id, int _pos, char _letter) : id(_id), pos(_pos), letter(_letter) {}
};

pair<int,op> memo[MxN][MxN];
int n, m;

string optos(int op) {
	if (op == INS) return " Insert ";
	if (op == DEL) return " Delete ";
	if (op == REP) return " Replace ";
	return "";
}

void debmemo() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			cout << setw(3) << memo[i][j].first << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve(string& s1, string& s2) {
	n = s1.size(); m = s2.size();
	memset(memo, 0, sizeof(memo));
	for (int i = 1; i <= n; ++i) {
		memo[i][0].first = memo[i-1][0].first-1;
		memo[i][0].second = op(DEL, i, s1[i-1]);
	}

	for (int i = 1; i <= m; ++i) {
		memo[0][i].first = memo[0][i-1].first-1;
		memo[0][i].second = op(INS, i, s2[i-1]);
	}

	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int match = s1[i-1] == s2[j-1] ? 2 : 0;
			int cdel = memo[i-1][j].first-1;
			int cins = memo[i][j-1].first-1;
			int crep = memo[i-1][j-1].first + match;
			if (cins > cdel)
				if (cins > crep) {
					memo[i][j].first = cins;
					memo[i][j].second = op(INS, j, s2[j-1]);
				}
				else {
					memo[i][j].first = crep;
					memo[i][j].second = op(match == 2 ? NOT : REP, j, s2[j-1]);
				}
			else
				if (cdel > crep) {
					memo[i][j].first = cdel;
					memo[i][j].second = op(DEL, j, s2[j-1]);
				}
				else {
					memo[i][j].first = crep;
					memo[i][j].second = op(match == 2 ? NOT : REP, j, s2[j-1]);
				}
		}
	}


	vector<op> ans;
	pair<int, int> pos = {n,m};
	int i = 1;
	int ops = 0;
	// debmemo();
	while(pos != make_pair(0,0)) {
		op currop = memo[pos.first][pos.second].second;
		ans.push_back(currop);
		if (currop.id != NOT) ops++;
		if (currop.id != INS) pos.first--;
		if (currop.id != DEL) pos.second--;
	}

	reverse(ans.begin(), ans.end());
	int where = 1;
	cout << ops << endl;
	for (op currop : ans) {
		if (currop.id != NOT) {
			string letter = "";
			if (currop.id != DEL) {
				letter = ",";
				letter.push_back(currop.letter);
			}
			cout << i++ << optos(currop.id) << where << letter << endl;
		}
		// if (currop.id == INS) where++;
		if (currop.id == DEL) where--;
		where++;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool first = true;

    string s1, s2;
    while (getline(cin, s1), getline(cin, s2)) {
    	if (!first) {
    		cout << endl;
    	}
    	first = false;
    	solve(s1, s2);
    }
    


	return 0;
}