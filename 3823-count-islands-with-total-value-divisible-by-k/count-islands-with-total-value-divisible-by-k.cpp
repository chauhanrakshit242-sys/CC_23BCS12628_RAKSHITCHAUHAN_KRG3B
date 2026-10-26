class Solution {
public:
    // Change return type to long long to accumulate the island's total value safely
    long long dfs(int i, int j, const vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[i][j] = 1;
        long long current_sum = grid[i][j]; // Start with the value of the current cell

        // Directions array makes checking neighbors much cleaner
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int ni = i + dr[d];
            int nj = j + dc[d];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                // If it's land (grid[ni][nj] > 0) and not yet visited
                if (grid[ni][nj] > 0 && vis[ni][nj] != 1) {
                    current_sum += dfs(ni, nj, grid, vis, n, m);
                }
            }
        }
        return current_sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int island_count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // If we find an unvisited land cell (value > 0)
                if (grid[i][j] > 0 && vis[i][j] != 1) {
                    long long total_value = dfs(i, j, grid, vis, n, m);
                    
                    // Check if the total sum of this island is divisible by k
                    if (total_value % k == 0) {
                        island_count++;
                    }
                }
            }
        }

        return island_count;
    }
};