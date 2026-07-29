class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Push all rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int maxi = 0;

        while (!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxi = max(maxi, time);

            // Left
            if (c - 1 >= 0 && grid[r][c - 1] == 1 && !vis[r][c - 1]) {
                vis[r][c - 1] = 1;
                q.push({{r, c - 1}, time + 1});
            }

            // Right
            if (c + 1 < m && grid[r][c + 1] == 1 && !vis[r][c + 1]) {
                vis[r][c + 1] = 1;
                q.push({{r, c + 1}, time + 1});
            }

            // Up
            if (r - 1 >= 0 && grid[r - 1][c] == 1 && !vis[r - 1][c]) {
                vis[r - 1][c] = 1;
                q.push({{r - 1, c}, time + 1});
            }

            // Down
            if (r + 1 < n && grid[r + 1][c] == 1 && !vis[r + 1][c]) {
                vis[r + 1][c] = 1;
                q.push({{r + 1, c}, time + 1});
            }
        }

        // Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return maxi;
    }
};