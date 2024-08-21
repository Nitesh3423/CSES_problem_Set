#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
#define          sti                   size_t
 

void solve() {
    ll x,n;
    cin>>x>>n;
    set<ll> positions;
    multiset<ll> segments;
    positions.insert(0);
    positions.insert(x);
    segments.insert(x);
    for(ll i=0;i<n;i++){
        ll pos;
        cin>>pos;
        
        //finding closest postion greater than or equal to the pos in position se
        auto it=positions.lower_bound(pos);
        ll right=*it;
        it--;
        ll left=*it;
        //remove old segment
        segments.erase(segments.find(right-left));
        //add new segments
        segments.insert(pos-left);
        segments.insert(right-pos);
        //insert new traffic light pos

        positions.insert(pos);
        cout<<*segments.rbegin()<<" ";
    }
    cout<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
