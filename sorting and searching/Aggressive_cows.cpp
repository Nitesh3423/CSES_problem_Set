#include "bits/stdc++.h"
using namespace std;
 
#define          ll                   long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
#define          sti                   size_t
 

bool canPlace(vectot<ll> &stalls , ll dist, ll k){
    ll n=stalls.size();
    ll cnt=1;
    ll last=stall[0];
    for(ll i=1;i<n;i++){
        if(stalls[i]>=dist){
            cnt++;
            last=stalls[i];
        }
        if(cnt>=k) return true;
    }
    return false;
}
void solve() {
    ll n;
    cin>>n;
    ll c;
    cin>>c;
    vector<ll> position(n+1);
    for(ll i=0;i<n;i++){
        cin>>position[i];
    }
    sort(all(position));
    ll limit=position[n-1]-position[0];
    for(ll i=1;i<=limit;i++){
        if(canPlace(position , i, c)==false){
            cout<<(i-1)<<endl;
            return;
        }
    }
    cout<<limit<<endl;
    return;
}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}