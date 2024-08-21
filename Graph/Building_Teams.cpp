#include <bits/stdc++.h>
using namespace std;
bool bfs(int start,vector<vector<int>>& adj,vector<int>& teams){
    queue<int> q;
    q.push(start);
    teams[start]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(teams[it]==-1){
                teams[it]=3-teams[node];
                q.push(it);
            }
            else if(teams[it]==teams[node]){
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

   vector<int> teams(n+1,-1);
   for(int i=1;i<=n;i++){
    if(teams[i]==-1){
        if(!bfs(i,adj,teams)){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
   }
   for(int i=1;i<=n;i++){
    cout<<teams[i]<<" ";
   }
   cout<<endl;
    return 0;
}
