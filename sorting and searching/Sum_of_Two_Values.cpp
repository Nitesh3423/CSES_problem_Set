#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> solve(vector<long long>& nums, long long x) {
    unordered_map<long long, long long> mp;
    mp.reserve(nums.size()); // Reserve space to avoid rehashing
    for (size_t i = 0; i < nums.size(); i++) {
        long long complement = x - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false); // Disable sync with C stdio
    cin.tie(NULL); // Untie cin from cout for faster I/O

    long long n, x;
    cin >> n >> x;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++) {
        cin >> nums[i];
    }
    pair<long long, long long> p = solve(nums, x);
    if (p.first == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << p.first + 1 << " " << p.second + 1 << endl; // To make the indices 1-based
    }
    return 0;
}
