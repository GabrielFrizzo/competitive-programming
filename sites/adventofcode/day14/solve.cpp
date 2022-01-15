#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
using pcc = pair<char, char>;

const int MxN = 5123;
const int MOD = 1e9 + 7;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string inp;
	cin >> inp;
	map<pcc, ll> pairs;
	for(int i = 0; i < inp.size()-1; ++i) {
		pairs[{inp[i], inp[i+1]}]++;
	}

	map<pcc, char> dict;
	int rules;
	cin >> rules;
	while(rules--) {
		char k1, k2, v;
		cin >> k1 >> k2 >> v;
		dict[{k1, k2}] = v;
	}

	map<pcc, ll> new_pairs;
	for(int RUN = 1; RUN <= 10; ++RUN) {
		new_pairs.clear();
		for (pair<pcc, char> rule : dict) {
			pcc k1 = {rule.first.first, rule.second};
			pcc k2 = {rule.second, rule.first.second};
			new_pairs[k1] += pairs[rule.first];
			new_pairs[k2] += pairs[rule.first];
		}

		cout << endl << RUN << endl;
		for(pair<pcc, ll> p : pairs) {
			cerr << p.first.first << p.first.second << ' ' << p.second << endl;
		}

		pairs = new_pairs;
	}

	map<char, ll> cnts;
	for (pair<pcc, ll> p : pairs) {
		cnts[p.first.first] += p.second;
		cnts[p.first.second] += p.second;
	}
	cnts[*inp.begin()]++;
	cnts[*inp.rbegin()]++;
	for (pair<char, ll> p : cnts) {
		cnts[p.first] = p.second / 2;
	}

	ll worst = 1e18, best = 0;
	char cworst, cbest;
	for(pair<char, ll> pci : cnts) {
		if (pci.second > best) {
			best = pci.second;
			cbest = pci.first;
		}
		if (pci.second < worst) {
			worst = pci.second;
			cworst = pci.first;
		}
	}
	cerr << cbest << ": " << best << endl;
	cerr << cworst << ": " << worst << endl;

	cout << best - worst << endl;
	return 0;
}