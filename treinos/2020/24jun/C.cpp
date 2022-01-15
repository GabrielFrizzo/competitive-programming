#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

string s;
int N;

bool validate(string res) {
	// cout << res << endl;
	if (res == "NO") return false;
	int M = N/2+1;
	for (int pos = M; pos < N; ++pos) {
		int c = 0;
		for (int i = 0; i <= pos; ++i) {
			if (pos-i < M && i < M) {
				c += (res[i]-'0')*(res[pos-i]-'0');
			}
		}
		// cout << "xabironga" << pos << ' ' << c << ' ' << s[pos] << endl;
		if (s[pos]-'0' != c%10)
			return false;
	}
	return true;
}

string dfs(int pos, string res) {
	// cout << pos << ' ' << res << endl;

	if (pos > N/2) return res;

	int c = 0;

	for (int i = 1; i < pos; ++i) {
		c += (res[i]-'0')*(res[pos-i]-'0');
	}

	for (int i = 0; i < 10; ++i) {
		// cout << i << "D" << (c + 2*i*res[0])%10 << endl;
		if (s[pos]-'0' == ((c + 2*i*(res[0]-'0'))%10)) {
			string response = dfs(pos+1, res + to_string(i));
			if (response != "NO") {
				if (pos == N/2) {
					if (validate(res + to_string(i))) return res + to_string(i);
				} else {
					return response;
				}
			}
		}
	}

	return "NO";
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> s;
    N = s.size();

    if ((N&1) == 0) {
    	cout << -1 << endl;
    	return 0;
    }
    string res = "NO";
    for (int i = 0; i < 10; ++i) {
    	if ((i*i)%10 == s[0]-'0') {
    		res = dfs(1, to_string(i));
    		if (res != "NO") {
				cout << res << endl;
				return 0;
    		}
    	}
    }

	cout << -1 << endl;

	return 0;
}


// 11112
// 123476544


// c[5] = a0a5 + a1a4 + ... + a5a0