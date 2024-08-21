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
    vector<pair<ll,ll>> tasks(n);
    for(ll i=0;i<n;i++){
        cin>>tasks[i].first>>tasks[i].second;
    }
    sort(tasks.begin(),tasks.end());
    ll total_reward=0;
    ll finish_time=0;
    for(auto it:tasks){
        ll duration=it.first;
        ll deadline=it.second;
        //ll reward= deadline-finish_time;
        finish_time+=duration;
        total_reward+=(deadline-finish_time);

    }
    cout<<total_reward<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
