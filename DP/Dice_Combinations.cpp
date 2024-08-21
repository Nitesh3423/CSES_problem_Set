#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
vector<int> memo;

int countWays(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    
    if (memo[n] != -1) return memo[n];
    
    int ways = 0;
    for (int i = 1; i <= 6; ++i) {
        ways += countWays(n - i);
    }
    return memo[n] = ways;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6 and i-j>=0;j++){
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
