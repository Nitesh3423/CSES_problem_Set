#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long countWays(int n, int sum, vector<int> &coins, vector<long long> &dp)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (dp[sum] != -1)
        return dp[sum];
    long long ways = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= sum)
        {
            ways = (ways + countWays(n, sum - coins[i], coins, dp)) % MOD;
        }
    }
    return dp[sum] = ways;
}
int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> coins(N);
    vector<long long > dp(X+1,-1);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    long long  ans=countWays(N,X,coins,dp);
    cout<<ans<<endl;
    return 0;
}
