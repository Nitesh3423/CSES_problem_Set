#include <bits/stdc++.h>
using namespace std;

long long n;

vector<long long> shortest_route(long long src, vector<vector<pair<long long, long long>>>& adj) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    vector<long long> dis(n + 1, INT_MAX);
    pq.push({0, src});  // Distance first, then node
    dis[src] = 0;

    while (!pq.empty()) {
        long long distance = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        if (distance > dis[node]) continue;

        for (auto it : adj[node]) {
            long long node1 = it.first;
            long long wt = it.second;
            if (distance + wt < dis[node1]) {
                dis[node1] = distance + wt;
                pq.push({dis[node1], node1});
            }
        }
    }
    return dis;
}
int main() {
    long long m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(n + 1);
    for (long long i = 0; i < m; i++) {
        long long u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<long long> ans = shortest_route(1, adj);
    for (long long i = 1; i <= n; i++) {  // Output from index 1 to n
        if (ans[i] == INT_MAX)
            cout << "INF ";
        else
            cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
