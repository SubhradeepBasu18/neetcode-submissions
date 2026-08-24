class Solution {
private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>adj){
        
        vis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        int cnt = 0;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};
