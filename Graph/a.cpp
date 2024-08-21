#include <bits/stdc++.h>
using namespace std;
int limit;
vector<int> shortest_route(int src, vector<vector<pair<int, int>>> &adj,int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> dis(n + 1, INT_MAX);
    pq.push({0, src}); // Distance first, then node
    dis[src] = 0;

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance > dis[node])
            continue;

        for (auto it : adj[node])
        {
            int node1 = it.first;
            int wt = it.second;
            if (distance + wt <= limit and distance + wt < dis[node1])
            {
                dis[node1] = distance + wt;
                pq.push({dis[node1], node1});
            }
        }
    }
    return dis;
}
vector<vector<int>> findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    limit = distanceThreshold;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp = shortest_route(i, adj,n);
        grid[i]=temp;
    }
    return grid;
}

int main()
{
    vector<vector<int>> edges={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int maxi=4;
    int n=4;
    vector<vector<int>> ans= findTheCity(n, edges,maxi);
    unordered_map<int,int> mp;
    for(size_t i=0;i<ans.size();i++){
        for(size_t j=0;j<ans[i].size();j++){
            if(ans[i][j]!=INT_MAX){
                mp[i]++;
            }
        }
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}