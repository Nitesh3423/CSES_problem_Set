#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> find_cycle(int n, vector<vector<int>>& adj) {
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    stack<int> dfs_stack;
    
    for (int start = 1; start <= n; ++start) {
        if (visited[start]) continue;
        
        dfs_stack.push(start);
        parent[start] = start;
        
        while (!dfs_stack.empty()) {
            int node = dfs_stack.top();
            dfs_stack.pop();
            
            if (!visited[node]) {
                visited[node] = true;
                
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        dfs_stack.push(neighbor);
                        parent[neighbor] = node;
                    } else if (neighbor != parent[node]) {
                        // A cycle is found
                        vector<int> cycle;
                        cycle.push_back(neighbor);
                        
                        for (int cur = node; cur != neighbor; cur = parent[cur]) {
                            cycle.push_back(cur);
                        }
                        cycle.push_back(neighbor);
                        
                        reverse(cycle.begin(), cycle.end());
                        return cycle;
                    }
                }
            }
        }
    }
    
    return {};
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
    
    vector<int> cycle = find_cycle(n, adj);
    
    if (cycle.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << cycle.size() << endl;
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << endl;
    }
    
    return 0;
}
