#include<bits/stdc++.h>
using namespace std;
long long solve(int n,vector<long long>& dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int N=n;
    long long ans=INT_MAX;
    while(N>0){
        int digit=N%10;
        if(digit!=0) ans=min(ans , solve(n-digit,dp)+1);
        N=N/10;
    }
    return dp[n]= ans;
}
int main(){
    int n;
    cin>>n;
    vector<long long> dp(n+1,-1);
    long long ans=solve(n,dp);
    cout<<ans<<endl;
    return 0;
}