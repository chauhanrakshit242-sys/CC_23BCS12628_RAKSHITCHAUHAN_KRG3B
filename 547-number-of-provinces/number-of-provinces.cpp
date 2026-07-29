class Solution {
public:
    void dfs(int start, vector<vector<int>>& adjList, vector<bool>& vis) {
        vis[start] = true;

        for (auto neighbor : adjList[start]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<vector<int>> adjList(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjList, vis);
            }
        }

        return count;
    }
};