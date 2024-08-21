#include <bits/stdc++.h>
using namespace std;
 const long long  MOD = 1e9 + 7;
int  main() {
    long long  N, X;
    cin >> N >> X;
    vector<long long > coins(N);
    for (long long  i = 0; i < N; i++) {
        cin >> coins[i];
    }

   
    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1));
    for (long long  i = 0; i < N + 1; i++) {
        for (long long  j = 0; j < X + 1; j++) {
            if (i == 0 && j > 0) {
                dp[i][j] = 0;
            } else if (j == 0) {
                dp[i][j] = 1;
            } else if (coins[i - 1] <= j) {
                dp[i][j] = (dp[i][j - coins[i - 1]] + dp[i - 1][j]) % MOD;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][X] % MOD << endl;
    return 0;
}
