class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n, 0);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        // node, parent
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            vis[node] = 1;

            for(auto it: adj[node]){
                if(!vis[it]) q.push({it, node});
                else if(vis[it] && it != parent) return false;
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
