#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

#define MAX 2123456

ll phi[MAX];
ll dep[MAX];

void crivo (int n){
	for (int i = 0; i <= n+1  ; i++)
		phi[i] = 1;
	for (int i = 2;i<=n;i++){
		if (phi[i] == 1){
			ll t = i-1;

			for ( int j = i ; j <= n  ; j += i)
				phi[j] *= t;
			
			ll v = i*(t = i);
			
			while ( v < n ){
				for (int j = v ; j <= n ; j+=v)
					phi[j] *= t;
				v*=i;
			}
		}
	}
} 


void depth (int n){
	dep[1] = 0;
	for (int i = 2; i <= n ; i++){
		dep[i] = dep[phi[i]]+1;
	}
}


int main(){
	crivo(2e6);
	depth(2e6);

	vector<long long> prefarray; prefarray.push_back(0);
	ll total = 0;
	for (int i = 1; i < MAX; ++i) {
		total += dep[i];
		prefarray.push_back(total);
	}

	int N,n,m;
	scanf("%d",&N);
	while (N--){
		scanf ("%d %d",&m,&n);
		
		printf("%lld\n",prefarray[n]-prefarray[m-1]);
	}

	return 0;
}
