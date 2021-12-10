#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;


int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, cont =0;
	char c;
	float v, g;
	int vint;
	cin >> n>>c>>v;
	vint = (int) v*100;
	while(n--) {
		cin>>c>>g;
		v+=g*100;
		if ((int)(v)%100)
		{
			cont++;
		}
	}
	cout<<cont<<'\n';
	return 0;
}