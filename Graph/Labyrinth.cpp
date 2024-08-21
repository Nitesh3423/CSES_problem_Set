#include <bits/stdc++.h>
using namespace std;

int n, m;
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};

bool isValid(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
    return (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] != '#' && !vis[row][col]);
}

pair<string, int> findPath(pair<int, int> start, pair<int, int> end, vector<vector<char>>& grid) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        if (current == end) {
            string path;
            int len = dist[current.first][current.second];
            while (current != start) {
                pair<int, int> p = parent[current.first][current.second];
                if (p.first == current.first - 1) path += 'D';
                else if (p.first == current.first + 1) path += 'U';
                else if (p.second == current.second - 1) path += 'R';
                else if (p.second == current.second + 1) path += 'L';
                current = p;
            }
            reverse(path.begin(), path.end());
            return {path, len};
        }
        for (int i = 0; i < 4; i++) {
            int newrow = current.first + delrow[i];
            int newcol = current.second + delcol[i];
            if (isValid(newrow, newcol, grid, vis)) {
                q.push({newrow, newcol});
                vis[newrow][newcol] = 1;
                dist[newrow][newcol] = dist[current.first][current.second] + 1;
                parent[newrow][newcol] = current;
            }
        }
    }

    return {"", -1}; // No path found
}

int main() {
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start = {i, j};
            } else if (grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    pair<string, int> result = findPath(start, end, grid);
    if (result.first.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << result.second << endl;
        cout << result.first << endl;
    }

    return 0;
}
