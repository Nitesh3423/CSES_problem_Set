#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int solve(vector<int>& cost,int n){
    int sum=(n*(n+1))/2;
    if(sum%2==1){
        return 0;
    }
    sum=sum/2;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(cost[i-1]<=j){
                dp[i][j]=(dp[i-1][j-cost[i-1]]+dp[i-1][j])%MOD;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cost[i]=i+1;
    }
    
    int ans=solve(cost,n);
    cout<<ans<<endl;
    return 0;
}