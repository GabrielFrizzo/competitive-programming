#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 112345;
const int MOD = 1e9 + 7;

int binario [MxN];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, aux, value;
	cin >> n;
	aux = n;
	while (n--) {
		cin >> value;
		while(1) {
			if (binario[value]) {
				binario[value] = 0;
				value++;
			} else {
				binario[value] = 1;
				break;
			}
		}
	}
	int m = 0;
	for (int i = 0; i<MxN;i++)
	{
		if (binario[i] == 1)
		{
			m++;
			if (m>2)
			{
				cout<<"N\n";
				return 0;
			}
		}
	}
	if (aux > 1)
		cout<<"Y\n";
	else
		cout << "N\n";

	return 0;
}