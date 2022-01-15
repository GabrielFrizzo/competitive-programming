#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+10, inf = 1e8+10;

int n, k, c, pref[maxn], dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> k >> c;

    for(int i=1; i<=n; i++){
        cin >> pref[i];

        pref[i] += pref[i-1];
    }

    for(int j=1; j<=k; j++) dp[0][j] = inf;

    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = dp[i-1][j];

            if(j and i >= c){
                dp[i][j] = min(dp[i][j], dp[i-c][j-1] + pref[i] - pref[i-c]);
            }
        }
    }

    cout << pref[n] - dp[n][k] << endl;

    return 0;
}