#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 112345678;

bitset <MAX> bs; 

void sieve (void){
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i*i<MAX; i++)
		if (bs[i]){
		for (ll j = i*i; j < MAX; j+=i) bs[j]=0;
	}}

int f(int x){
	return x*x + x + 41;
}

int main(){
	sieve();
	int a,b;
	while (scanf("%d %d",&a,&b)!=EOF){
		int n = b - a + 1, ans = 0;
		for (int i = a; i<=b ; i++){
			int p = f(i);
			ans += bs[p];
		}
		double res = (double)ans;
		res *= 100;
		res /= n;
		printf("%.2lf\n", res+0.000001);
	}	
	return 0; 
}