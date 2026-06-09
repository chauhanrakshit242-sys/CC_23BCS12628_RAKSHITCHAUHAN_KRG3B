class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times)
        {
            int u =it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto node = pq.top();
            int weight=node.first;
            int node_element=node.second;
            pq.pop();
            for(auto neighbor : adj[node_element])
            {
                 int adjNode=neighbor.first;
                 int edges_weight=neighbor.second;
                 if(weight+edges_weight < dist[adjNode])
                 {
                    dist[adjNode]=weight+edges_weight;
                    pq.push({dist[adjNode],adjNode});
                 }
            }
        }
       int maxi = 0;
       for(int i = 1; i <= n; i++)
        {
        if(dist[i] == INT_MAX)
         return -1;

         maxi = max(maxi, dist[i]);
           }
        return maxi;
    }
};