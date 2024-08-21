#include <bits/stdc++.h>
using namespace std;

// Check if all elements in the vector are negative
bool allNegative(const vector<long long>& nums) {
    for (auto num : nums) {
        if (num >= 0) {
            return false;
        }
    }
    return true;
}

// Find the minimum element in the vector
long long findMinimum(const vector<long long>& nums) {
    return *max_element(nums.begin(), nums.end());
}

// Solve for the maximum subarray sum
long long solve(const vector<long long>& nums) {
    if (allNegative(nums)) {
        return findMinimum(nums);
    }
    long long max_sum = 0;
    long long current_sum = 0;
    for (auto num : nums) {
        current_sum += num;
        if (current_sum < 0) {
            current_sum = 0;
        }
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false); // Disable sync with C stdio
    cin.tie(NULL); // Untie cin from cout for faster I/O

    long long n;
    cin >> n;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long ans = solve(nums);
    cout << ans << endl;
    return 0;
}
