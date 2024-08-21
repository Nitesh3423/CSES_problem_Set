#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
#define          sti                   size_t
 
 
void solve() {
    int n;
    cin >> n;
    vector<int> playlist(n);
    for(int i = 0; i < n; i++) {
        cin >> playlist[i];
    }
    
    unordered_set<int> current_window;
    int i = 0, j = 0, max_length = 0;

    while(j < n) {
        // Expand the window to the right by including playlist[j]
        while(j < n && current_window.find(playlist[j]) == current_window.end()) {
            current_window.insert(playlist[j]);
            j++;
        }
        
        // Update the maximum length
        max_length = max(max_length, j - i);

        // If a duplicate is found or we reached the end, contract the window from the left
        if(j < n) {
            while(i < j && playlist[i] != playlist[j]) {
                current_window.erase(playlist[i]);
                i++;
            }
            // Move i past the duplicate
            i++;
            j++;
        }
    }
    
    cout << max_length << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
