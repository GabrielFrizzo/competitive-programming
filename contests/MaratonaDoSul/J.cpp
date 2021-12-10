#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const int MxN = 5123;
const int MOD = 1e9 + 7;

int tab[1123][1123];
int out[1123][1123];
int n;

int access(int i, int j) {
	if (i >= 0 && j >= 0 && i < n && j < n) {
		return tab[i][j];
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> n;
	for(int i = 0; i<n;i++) {
		cin>>s;
		for(int j = 0; j<n;j++) {
			if(s[j] == '.') {
				tab [i][j] = 0;
			}
			else {
				tab [i][j] = 1;
			}
		}
	}
	int a[2];
	// for (int i = 0; i < n; i++)
	// {
	// 	a[0] = 0;
	// 	a[1] = 0;
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		if(tab[i][j] == 0)
	// 		{
	// 			if(a[0] ==1)
	// 			{
	// 				out[i][j]++;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			a[0] = 1;
	// 		}
	// 		if(tab[i][n-j-1]==0)
	// 		{
	// 			if(a[1] ==1)
	// 			{
	// 				out[i][n-j-1]++;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			a[1] = 1;

	// 		}
	// 	}
	// }
	// for (int i = 0; i < n; i++)
	// {
	// 	a[0] = 0;
	// 	a[1] = 0;
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		if(tab[j][i] == 0)
	// 		{
	// 			if(a[0] ==1)
	// 			{
	// 				out[j][i]++;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			a[0] = 1;
	// 		}
	// 		if(tab[n-j-1][i]==0)
	// 		{
	// 			if(a[1] ==1)
	// 			{
	// 				out[n-j-1][i]++;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			a[1] = 1;

	// 		}
	// 	}
	// }
	for (int i = 0; i < n; ++i) {
		bool foundida = false, foundfrida = false, foundida2 = false, foundfrida2 = false;
		bool found_ida = false, found_frida = false, found_ida2 = false, found_frida2 = false;
		for (int j = 0; j < n; j++) {
			// if(access(i+j, j) == 0) {
			// 	if(foundida) {
			// 		out[i+j][j]++;
			// 	}
			// } else {
			// 	foundida = true;
			// }

			// if(access(n-i-j-1, n-j-1) == 0) {
			// 	if(foundfrida) {
			// 		out[n-i-j-1][n-j-1]++;
			// 	}
			// } else {
			// 	foundfrida = true;
			// }

			// if(access(j, i+j) == 0) {
			// 	if(foundida2) {
			// 		out[j][i+j]++;
			// 	}
			// } else {
			// 	foundida2 = true;
			// }

			// if(access(n-j-1, n-i-j-1) == 0) {
			// 	if(foundfrida2) {
			// 		out[n-j-1][n-i-j-1]++;
			// 	}
			// } else {
			// 	foundfrida2 = true;
			// }

			if(access(i+j, n-j-1) == 0) {
				if(found_ida) {
					out[i+j][n-j-1]++;
				}
			} else {
				found_ida = true;
			}

			if(access(n-i-j-1, j) == 0) {
				if(found_frida) {
					out[n-i-j-1][j]++;
				}
			} else {
				found_frida = true;
			}

			if(access(j, n-i-j-1) == 0) {
				if(found_ida2) {
					out[j][n-i-j-1]++;
				}
			} else {
				found_ida2 = true;
			}

			if(access(n-j-1, i+j) == 0) {
				if(found_frida2) {
					out[n-j-1][i+j]++;
				}
			} else {
				found_frida2 = true;
			}
		}
	}
	
	for(int i = 0; i < n ;i++) {
		for(int j = 0; j < n;j++) {
			cout<<out[i][j] << ' ';
		}
		cout<<endl;
	}
	return 0;
}