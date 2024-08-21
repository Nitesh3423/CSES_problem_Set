#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (ll )a.size()
#define          sti                   size_t

bool comp(vector<ll>& a,vector<ll>& b){
    if(a[1]==b[1]){
        return a[2] > b[2];
    }
    return a[1] < b[1];
}
void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> tasks;
    for(int i=0;i<n;i++){
        ll a,b,p;
        cin>>a>>b>>p;
        tasks.push_back({a,b,p});
    }
    sort(all(tasks),comp);
    vector<ll> dp(n);
    dp[0]=tasks[0][2];
    for(int i=1;i<n;i++){
        ll includeProfit=tasks[i][2];
        int low=0,high=i-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(tasks[mid][1] < tasks[i][0]){
                if(tasks[mid+1][1] < tasks[i][0]){
                    low=mid+1;
                }else{
                    includeProfit+=dp[mid];
                    break;
                }
            }else{
                high=mid-1;
            }
        }
        dp[i]=max(dp[i-1],includeProfit);
    }
    cout<<dp[n-1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
