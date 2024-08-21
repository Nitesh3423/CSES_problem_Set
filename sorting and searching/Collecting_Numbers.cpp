#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
#define          sti                   size_t
 
void solve() {
    ll n;
    cin>>n;
    vector<ll> nums(n);
    ll ans=1;
    for(ll i=0;i<n;i++) cin>>nums[i];
    vector<ll> indices(n+1);
    for(ll i=0;i<n;i++) indices[nums[i]]=i;

    for(ll num=1;num<n;num++){
        if(indices[num+1]<indices[num]){
            ans++;
        }
    }
    cout<<ans<<endl;
}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}