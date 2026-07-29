class Solution {
public:
    void dfs(int start, int end, vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        if (start < 0 || end < 0 || start >= n || end >= m ||
            vis[start][end] || grid[start][end] != '1')
            return;

        vis[start][end] = true;

        dfs(start - 1, end, grid, vis);
        dfs(start + 1, end, grid, vis);
        dfs(start, end - 1, grid, vis);
        dfs(start, end + 1, grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};