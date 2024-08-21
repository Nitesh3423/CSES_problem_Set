#include <bits/stdc++.h>
using namespace std;

int main() {
    long long  n, x;
    cin >> n >> x;
    vector<long long > weights(n);
    for (long long  i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    
    long long  left = 0;
    long long  right = n - 1;
    long long  gondolas = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            // Pair the lightest and the heaviest child together
            left++;
            right--;
        } else {
            // Only the heaviest child goes in a gondola
            right--;
        }
        gondolas++;
    }

    cout << gondolas << endl;
    return 0;
}
