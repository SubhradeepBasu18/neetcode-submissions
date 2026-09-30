class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>dist(n, 1e9);
        queue<pair<int,pair<int,int>>>q;

        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }

        dist[src] = 0;
        // stops, {node, cost}
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            if(stops>k) continue;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dist[adjNode]>cost+wt){
                    dist[adjNode] = cost+wt;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
