#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance
int editDistance(const string &a, const string &b){
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the base cases
    for (int i = 0; i <= n; i++){
        dp[i][0] = i; // Minimum operations needed to convert a substring of a to an empty string
    }
    for (int j = 0; j <= m; j++){
        dp[0][j] = j; // Minimum operations needed to convert an empty string to a substring of b
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no operation needed
            }
            else{
                dp[i][j] = min({
                    dp[i - 1][j] + 1,    // Delete a character from a
                    dp[i][j - 1] + 1,    // Insert a character into a
                    dp[i - 1][j - 1] + 1 // Replace a character in a
                });
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string a, b;
    cin >> a >> b;
    int result = editDistance(a, b);
    cout << result << endl;
    return 0;
}
