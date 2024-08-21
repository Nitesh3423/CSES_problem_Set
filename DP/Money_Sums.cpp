#include<bits/stdc++.h>
using namespace std;
unordered_map<long long , unordered_set<long long >> dp;
void solve(long long  index,vector<long long > coins,set<long long >& st, long long  n , long long  sum){
    if(index>=n){
        st.insert(sum);
        return;
    }
    //take
    if(dp[index].find(sum)!=dp[index].end()){
        return;
    }

    dp[index].insert(sum);
    solve(index+1,coins,st, n , sum+coins[index]);
    //not take
    solve(index+1,coins,st, n , sum);

}
int  main(){
    long long  n;
    cin>>n;
    vector<long long > coins(n);
    for(long long  i=0;i<n;i++){
        cin>>coins[i];
    }
    long long maxSum=accumulate(coins.begin(),coins.end(),0);
    vector<bool> dp(maxSum+1,false);
    dp[0]=true;
    for(long long  coin:coins){
        for(long long sum=maxSum;sum>=coin;sum--){
            if(dp[sum-coin]){
                dp[sum]=true;
            }
        }
    }
    set<long long > st;
    for(long long  sum=1;sum<=maxSum;sum++){
        if(dp[sum])  st.insert(sum);
    }
    cout<<st.size()<<endl;
    for(long long  it:st){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}