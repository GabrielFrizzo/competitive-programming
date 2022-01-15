#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int a, b;

int f(int mid) {
	// cout << mid << ": " << mid + min(b-mid*2, (a-mid)/2) << endl;
	return mid + min(b-mid*2, (a-mid)/2);
}

void solve() {
	cin >> a >> b;

	if (b>a) {
		int aux = a;
		a = b;
		b = aux;
	}
	
	int inf=0,sup= b/2;
	while (sup-inf>=3){
		int aa = inf + (sup-inf)/3, bb = sup - (sup-inf)/3;
		int fa = f(aa), fb = f(bb);
		if (fa > fb) sup = bb;
		else if (fa < fb) inf = aa;
		else { inf = aa; sup = bb;} 
	}
	int ans = f(inf)>f(sup)?inf:sup;
	if (sup-inf == 2) ans = f(ans)>f(inf+1)?ans:inf+1;

	cout << f(ans) << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
    	solve();
    }
	return 0;
}
