#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    while(cin >> N >> K, N) {
    	int inp;
    	unordered_map<int, int> umap;
    	while (N--) {
    		cin >> inp;
    		umap[inp]++;
    	}

    	int total=0;
    	for (pii p : umap)
    		if (p.second >= K)
    			total++;

    	cout << total << endl;
    }
	return 0;
}