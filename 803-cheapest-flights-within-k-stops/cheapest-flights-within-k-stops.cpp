class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        queue<vector<int>>q;
        dist[src]=0;
        q.push({0,src,0});
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int weight =node[0];
            int element=node[1];
            int count =node[2];
            if(count>k)
            continue;
            for(auto neighbor : adj[element])
            {
                int adjNode=neighbor.first;
                int edgesweight=neighbor.second;
                if(weight + edgesweight < dist[adjNode]&& count <=k)
                {
                   dist[adjNode]=weight+edgesweight;
                   q.push({dist[adjNode],adjNode,count+1});
                }
            }
        }
        return dist[dst]==INT_MAX ? -1:dist[dst];
    }
};