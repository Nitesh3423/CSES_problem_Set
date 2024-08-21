#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX / 2;

struct Edge {
    int u, v;
    long long weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long x;
        cin >> u >> v >> x;
        edges[i] = {u, v, x};
    }

    vector<long long> dist(n + 1, -INF);
    dist[1] = 0;

    // Bellman-Ford algorithm
    for (int i = 1; i < n; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != -INF && dist[edge.u] + edge.weight > dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for positive weight cycles
    vector<bool> inPositiveCycle(n + 1, false);
    for (int i = 1; i <= n; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != -INF && dist[edge.u] + edge.weight > dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                inPositiveCycle[edge.v] = true;
            }
        }
    }

    // Propagate positive cycle influence
    queue<int> q;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (inPositiveCycle[i] && !visited[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (const auto& edge : edges) {
            if (edge.u == node && !visited[edge.v]) {
                visited[edge.v] = true;
                q.push(edge.v);
            }
        }
    }

    if (visited[n]) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }

    return 0;
}
