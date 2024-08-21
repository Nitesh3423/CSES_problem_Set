#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
/* int solve(int index, vector<int>& nums,int prev,int n,vector<vector<int>>& dp){
    if(index==n){
        return 0;
    }
    //take
    if(dp[index][prev+1]!=-1) return dp[index][prev+1];
    int take=0;
    if(prev == -1 or nums[index]>nums[prev]){
        take=1+solve(index+1,nums,index,n,dp);
    }
    int notTake=solve(index+1,nums,prev,n,dp);

    return dp[index][prev+1]=  max(take,notTake);
} */


    //TABULATION APPROACH


    /* vector<vector<long long >> dp(n+1,vector<long long >(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int notTake= dp[i+1][j+1];
            int take=0;
            if(j==-1 or nums[i]>nums[j])  take= 1+dp[i+1][i+1];

            dp[i][j+1]=max(take,notTake);
        }
        
    } 
    int ans= dp[0][0];*/


    // 1D ARRAY APPROACH

    /* vector<long long> dp(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[i]>nums[prev]){
                dp[i]=max(dp[i],dp[prev]+1);
            }
        }
    }
    long long ans=-1;
    for(int i=0;i<=n-1;i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl; */
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    //BINARY SEARCH APPROACH

    vector<int> temp;
    int length=1;
    temp.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
            length++;
        }else{
            int lower_index=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[lower_index]=nums[i];
        }
    }
    cout<<length<<endl;
    return 0;
}