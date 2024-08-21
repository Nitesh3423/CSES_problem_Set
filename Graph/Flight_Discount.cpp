#include<bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> solve(int src, vector<vector<pair<int, int>>>& adj, int dest) {
    vector<int> dis(n + 1, INT_MAX);
    vector<int> maxEdge(n + 1, INT_MIN);  
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;
    maxEdge[src] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        
        if (distance > dis[node]) continue;

        for (auto it : adj[node]) {
            int node1 = it.first;
            int wt = it.second;

            if (distance + wt < dis[node1]) {
                dis[node1] = distance + wt;
                maxEdge[node1] = max(maxEdge[node], wt);
                pq.push({dis[node1], node1});
            }
        }
    }
    if (dis[dest] == INT_MAX) {
        return {INT_MAX, INT_MIN};
    }

    return {dis[dest], maxEdge[dest]};
}

int main() {
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    int src = 1;
    int dest = n;
    pair<int, int> ans = solve(src, adj, dest);
    int length = ans.first;
    int maxi = ans.second;

    length=length-maxi+(maxi/2);
    cout<<length<<endl;

    return 0;
}
