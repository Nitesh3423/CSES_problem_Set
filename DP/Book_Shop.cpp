    #include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;


int main(){
    int n,x;
    cin>>n>>x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1));  //{i->weight, j->budget}
    for(int i=1;i<n+1;i++){
        for(int j=1;j<x+1;j++){
            dp[i][j]=dp[i-1][j];
            if(prices[i-1]<=j){
                dp[i][j]=max(dp[i-1][j-prices[i-1]]+pages[i-1], dp[i][j]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}