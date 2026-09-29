class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n+1, 1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        //time, {node, cost}
        q.push({0,{k, 0}});
        dist[k] = 0;
        dist[0] = 0;

        for(auto time: times){
            int u = time[0];
            int v = time[1];
            int wt = time[2];

            adj[u].push_back({v,wt});
        }

        while(!q.empty()){
            auto it = q.front();
            int time = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dist[adjNode] > cost+wt){
                    dist[adjNode] = cost+wt;
                    q.push({time+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        int maxi = 0;
        for(int it: dist){
            if(it == 1e9) return -1;
            maxi = max(maxi, it);
        }
        return maxi;
    } 
};
