#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false); // Disable sync with C stdio
    cin.tie(NULL);                    // Untie cin from cout for faster I/O

    ll n;
    cin >> n;
    vector<ll> sticks(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    // Sort the sticks to find the median
    sort(sticks.begin(), sticks.end());

    // The median is the middle element in the sorted list
    ll median = sticks[n / 2];
    ll total_cost = 0;

    // Calculate the total cost to make all sticks the same length as the median
    for (ll i = 0; i < n; i++) {
        total_cost += abs(sticks[i] - median);
    }

    cout << total_cost << endl;

    return 0;
}
