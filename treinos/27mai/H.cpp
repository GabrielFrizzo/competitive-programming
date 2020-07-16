#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pdi = pair<double, int>;
using vi = vector<int>;
using ll = long long;

int popcount(int i) {
	int total = 0;
	while (i) {
		total += i&1;
		i>>=1;
	}
	return total;
}

void printa(vi& v, int n) {
	// cout << "n: " << n << endl;
	int count = 0;
	bool first = true;
	while (n) {
		if (n&1) {
			if (!first) cout << ' ';
			cout << v[count];
			first = false;
		}
		count++;
		n>>=1;
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vi inp1(N), inp2(M);
    vector<double> v1(N), v2(M);

    for (int i = 0; i < N; ++i) {
    	cin >> inp1[i];
    	v1[i] = log(inp1[i]);
    }
    for (int i = 0; i < M; ++i) {
    	cin >> inp2[i];
    	v2[i] = log(inp2[i]);
    }

    unordered_map<ll, int> umap1, umap2;

    for (int i = 1; i < 1<<N; ++i) {
    	int j = i;
    	double logs = 0;
    	int count = 0;
    	while (j) {
    		if (j&1) {
    			logs += v1[count];
    		}
    		count++;
    		j >>= 1;
    	}
    	umap1[(ll)(logs*1e12)] = i;
    }

    for (int i = 1; i < 1<<M; ++i) {
    	int j = i;
    	double logs = 0;
    	int count = 0;
    	while (j) {
    		if (j&1) {
    			logs += v2[count];
    		}
    		count++;
    		j >>= 1;
    	}
    	umap2[(ll)(logs*1e12)] = i;
    }

    // for (pdi p : umap2) {
    // 	cout << "2: " << p.first << endl;
    // }

    for (pair<ll, int> p : umap1) {
    	// cout << p.first << endl;
    	if (umap2.count(p.first)) {
    		cout << "Y" << endl;
    		cout << popcount(p.second) << ' ' << popcount(umap2[p.first]) << endl;
    		printa(inp1, p.second);
    		printa(inp2, umap2[p.first]);
    		return 0;
    	}
    }

    cout << "N" << endl;
	return 0;
}