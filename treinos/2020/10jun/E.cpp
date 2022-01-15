#include<bits/stdc++.h>

using namespace std;

const int MAX = 11234;

const int INF = 1e9;

int fita[MAX];
int sums[MAX];
int memo[MAX][MAX];
int n,c;

int dp (int i , int k){
	if (memo[i][k]!= INF) return memo[i][k];
	if (k <= 0) return 0;
	if (i > (n-c)) return INF-1;
	int ch1 = dp(i+c,k-1) + sums[i];
	int ch2 = dp(i+1,k);
	return memo[i][k] = min(ch1,ch2);
}

int main(){
	int ans = 0,k,sum = 0;
	scanf("%d %d %d",&n,&k,&c);
	for (int i = 0 ; i < n; i++){
		scanf ("%d",&fita[i]);
		ans += fita[i];
		if (i<c) sum+=fita[i];
		else {
			sums[i-c] = sum;
			sum += fita[i]-fita[i-c];	
		}

		for (int j = 0; j <= k ; j++)
			memo[i][j]=INF;
	}
	sums[n-c] = sum;
	for (int j = 0; j <= k ; j++)
		memo[n][j]=INF;

		
	printf ("%d\n",(ans - dp (0,k)));
	

	return 0;
}