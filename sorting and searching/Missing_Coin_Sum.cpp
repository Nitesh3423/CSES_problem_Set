#include "bits/stdc++.h"
using namespace std;

#define ll long long

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pb push_back
#define sz(a) (int)a.size()

void solve()
{
    int n;
    cin >> n ;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    sort(all(coins));
    ll sum=0;
    for(ll coin:coins){
        if(coin>sum+1){
            cout<<(sum+1)<<endl;
            return;
        }
        sum+=coin;
    }
    cout<<(sum+1)<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}