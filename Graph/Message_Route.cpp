#include<bits/stdc++.h>
using namespace std;
vector<int> path;
pair< vector<int> , vector<int> > dijkstra(int n,vector<vector<int>> &adj,int s,int destination){
    vector<int> dis(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    parent[s]=s;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int distance=p.first;
        int node=p.second;
        if(node==destination) break;
        for(auto it:adj[node]){
            if(distance+1<dis[it]){
                dis[it]=distance+1;
                parent[it]=node;
                pq.push({distance+1,it});
            }
        }
    }
    return {dis,parent};
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
    pair< vector<int> , vector<int> > p= dijkstra(n,adj,1,n);
    vector<int> dis= p.first;
    vector<int> parent= p.second;
    if(dis[n]==INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<dis[n]+1<<endl;
        vector<int> path;
        for(int index=n;index!=1;index=parent[index]){
            path.push_back(index);
        }
        reverse(path.begin(),path.end());
        cout<<'1'<<" ";
        for(int node:path){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}
