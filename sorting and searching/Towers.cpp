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
    vector<int> cubes(n);
    for(ll i=0;i<n;i++) cin>>cubes[i];
    multiset<ll> towers;
    ll ans=0;
    for(ll cube:cubes){
        auto it=towers.upper_bound(cube);
        if(it!=towers.end()){
            towers.erase(it);
        }
        towers.insert(cube);
    }
    cout<<towers.size()<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
