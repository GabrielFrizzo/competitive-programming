#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int alg[10];

int check (ll a){
	int _max=0;
	memset(alg,0,sizeof(alg));
	while (a){	
		ll resto = (a%10);
		_max=max(_max,++alg[resto]);
		a/=10;
	}
	return _max<3;
}

ll corrige (ll a){
	while (!check(a)) a--;
	return a;
}

int main(){

	while (true) {
		char c;
		ll ans = 0;
		int _max = 0, first = 1;
		memset(alg,0,sizeof(alg));
		while (	scanf("%c",&c),(c>='0'&&c<='9')){
			ll num = (ll) (c-'0');
			_max = max(_max,++alg[num]);
			
			if (_max<3){
				ans = 10*ans + num;
			}
			else{
				if (first) {
					first = 0; 
					ans = 10*ans + num;
					ans = corrige(ans);
				}
				else{
					ll xablau = (ll)(alg[9]>1?(alg[8]>1?(alg[7]>1?(alg[6]>1?(alg[5]>1?(alg[4]>1?(alg[3]>1?(alg[2]>1?(alg[1]>1?0:1):2):3):4):5):6):7):8):9);
					ans = 10*ans + xablau;
					alg[xablau]++;
				}
			}
		}
		if (ans == 0) break;
		printf("%lld\n",ans);

	}


	return 0; 
}
