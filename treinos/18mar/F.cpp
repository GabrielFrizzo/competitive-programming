#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    vector<pair<int, string>> pairs;
    string name;
    int yr, dt;


    while (true){
    	cin >> N;
    	if (N == 0) return 0;
    	pairs.clear();
    	for (int t = 0; t < N; t++) {
    		cin >> name >> yr >> dt;
    		pairs.push_back(make_pair(yr-dt, name));
    	}

    	sort(pairs.begin(), pairs.end());

    	cout << pairs[0].second << endl;
    }
	return 0;
}