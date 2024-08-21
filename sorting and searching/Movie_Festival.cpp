#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define sz(a) (int)a.size()
#define sti size_t

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> time;
    for (ll i = 0; i < n; i++) {
        ll start, end;
        cin >> start >> end;
        time.pb({start, end});
    }
    sort(all(time), comp);
    ll count = 0;
    ll lastEnd = -1;
    for (auto it : time) {
        if (it.first >= lastEnd) {
            count++;
            lastEnd = it.second;
        }
    }
    cout << count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
