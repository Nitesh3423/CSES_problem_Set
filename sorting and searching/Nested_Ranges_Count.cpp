#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
using namespace std;
 
#define          ll                   long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
#define          sti                   size_t


template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


bool comp(pair<pair<int,int> , int> a, pair<pair<int,int> , int> b){
    if(a.first.first==b.first.first){
        return a.first.second>b.first.second;
    }
    a.first.first < b.first.first;
}
void solve() {
    int n;
    cin>>n;
    oset<pair<int , int>> b,c;
    vector<pair< pair<int,int> , int>> ranges(n);  // {{x,y} , index}
    vector<int> aa(n),bb(n);
    for(int i=0;i<n;i++){
        cin>>ranges[i].first.first>>ranges[i].first.second;
        ranges[i].second=i;
    }
    sort(ranges.begin(),ranges.end,comp);
    for(int i=0,j=n-1;i<n;i++,j--){
        aa[ranges[j].second]=c.order_of_key({ranges[i].first.second+1 ,-1});
        c.insert({ranges[j].first.second , i});
    }
    for(int i=0;i<n;i++){
        bb[ranges[i].second]=i-b.order_of_key({ranges[i].first.second+1 ,-1});
        b.insert({ranges[i].first.second , i});
    }
    for(int i=0;i<n;i++){
        cout<<(aa[i])<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<(bb[i])<<" ";
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
