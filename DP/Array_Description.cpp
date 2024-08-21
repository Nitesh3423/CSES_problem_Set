#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define sz(a) (ll)a.size()
#define sti size_t

const int MOD = 1e9 + 7;

// Function to count the number of valid arrays
int countArrays(int n, int m, vector<int>& nums) {
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    // Initialize dp array
    for (int j = 1; j <= m; ++j) {
        if (nums[0] == 0 || nums[0] == j) {
            dp[0][j] = 1;
        }
    }

    // Fill the dp array
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (nums[i] == 0 || nums[i] == j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    // Calculate the result
    ll result = 0;
    for (int j = 1; j <= m; ++j) {
        result = (result + dp[n - 1][j]) % MOD;
    }

    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << countArrays(n, m, nums) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
