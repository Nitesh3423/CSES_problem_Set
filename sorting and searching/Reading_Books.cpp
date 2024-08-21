#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (ll )a.size()
#define          sti                   size_t
 
bool comp(pair<ll,ll> a , pair<ll,ll> b){
    return a.second<b.second;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> times(n);
    for(ll i=0;i<n;i++){
        cin>>times[i];
    }
    sort(all(times));
    ll largest=times[n-1];
    ll sumOfSmallest= accumulate(times.begin(),times.end()-1 , 0);
    if(largest<=sumOfSmallest){
        cout<<(largest+sumOfSmallest)<<endl;
    }else{
        cout<<(2*largest)<<endl;
    }
    
    //cout<<total_time<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
