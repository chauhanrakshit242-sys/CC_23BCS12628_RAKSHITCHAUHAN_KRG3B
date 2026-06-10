class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);

        minDist[0] = 0;

        int cost = 0;

        for(int i = 0; i < n; i++) {

            int u = -1;

            // Find node with minimum distance
            for(int v = 0; v < n; v++) {
                if(!inMST[v] &&
                   (u == -1 || minDist[v] < minDist[u])) {
                    u = v;
                }
            }

            inMST[u] = true;
            cost += minDist[u];

            // Update distances
            for(int v = 0; v < n; v++) {

                if(!inMST[v]) {

                    int dist =
                        abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);

                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return cost;
    }
};