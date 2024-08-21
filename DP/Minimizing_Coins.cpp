#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    vector<int> dp(X + 1, INT_MAX); 
    dp[0] = 0;
    
    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[X] == INT_MAX) {
        cout << "-1" << endl; // Not possible to make the sum
    } else {
        cout << dp[X] << endl; // Minimum number of coins needed
    }

    return 0;
}
