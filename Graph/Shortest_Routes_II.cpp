#include <bits/stdc++.h>
using namespace std;

const long long  INF = 1e9;

int  main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long  n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long >> dist(n + 1, vector<long long >(n + 1, INF));

    // Initialize distance from a node to itself to be zero
    for (long long  i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    // Read the edges and initialize the distance matrix
    for (long long  i = 0; i < m; ++i) {
        long long  a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    // Floyd-Warshall Algorithm
    for (long long  k = 1; k <= n; ++k) {
        for (long long  i = 1; i <= n; ++i) {
            for (long long  j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Answer the queries
    while (q--) {
        long long  a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}
