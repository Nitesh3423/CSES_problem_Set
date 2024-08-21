#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (ll )a.size()
#define          sti                   size_t
 

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> customers(n);
    for(ll i=0;i<n;i++){
        cin>>customers[i].first>>customers[i].second;
    }
    vector<pair<ll,ll>> arrivals,departures;
    for(ll i=0;i<n;i++){
        arrivals.push_back({customers[i].first , i});
        departures.push_back({customers[i].second , i});
    }
    sort(arrivals.begin(),arrivals.end());
    sort(departures.begin(),departures.end());
    priority_queue<ll ,vector<ll > , greater<ll >> availabeRooms;
    ll  roomsNeeded=0;
    vector<ll > roomAssigments(n);
    ll  roomCount=0;
    ll i=0,j=0;
    while(i<n and j<n){
        if(arrivals[i].first <= departures[j].first){
            if(availabeRooms.empty()){
                roomsNeeded++;
                roomCount++;
                roomAssigments[arrivals[i].second]=roomCount;
            }else{
                int room= availabeRooms.top();
                availabeRooms.pop();
                roomAssigments[arrivals[i].second]=room;
            }
            i++;
        }else{
            availabeRooms.push(roomAssigments[departures[j].second]);
            j++;
        }
    }
    cout<<roomsNeeded<<endl;
    for(auto it:roomAssigments){
        cout<<it<<" ";
    }
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
