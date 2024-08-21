#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (ll )a.size()
#define          sti                   size_t
 
int MOD=1e9+7;

void solve() {
   string s;
   cin>>s;
   int n;
   cin>>n;
   unordered_set<string> st;    
   for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    st.insert(temp);
   }
   vector<ll> dp(n+1,0);
   dp[0]=1;
   for(int i=1;i<=n;i++){
    for(string word:st){
        int len=word.length();
        if(i>=len and s.substr(i-len , len)==word){
            dp[i]=(dp[i-len]+dp[i])%MOD;
        }
    }
   }
   cout<<dp[n]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
