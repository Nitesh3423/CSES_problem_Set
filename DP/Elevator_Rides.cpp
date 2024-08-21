#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

using ll = long long;

int main() {
    ll n, wt;
    cin >> n >> wt;
    vector<ll> weights(n);
    for (ll i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Initialize the dp table
    vector<vector<ll>> dp(n + 1, vector<ll>(wt + 1, INT_MAX));

    // Base case: dp[0][0] is 0, meaning 0 people with 0 weight requires 0 rides
    dp[0][0] = 0;

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= wt; ++j) {
            // Carry forward the previous state without including the current person
            dp[i][j] = dp[i - 1][j];
            // If the current person's weight can be added to the current weight
            if (j >= weights[i - 1] && dp[i - 1][j - weights[i - 1]] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - weights[i - 1]]);
            }
        }
        // Increment the number of rides if current state cannot accommodate all people
        for (ll j = 0; j <= wt; ++j) {
            if (dp[i][j] != INT_MAX) {
                dp[i][j] += 1;
            }
        }
    }

    // Find the minimum number of rides needed for all n people
    ll result = INT_MAX;
    for (ll j = 0; j <= wt; ++j) {
        result = min(result, dp[n][j]);
    }

    cout << result << endl;

    return 0;
}
