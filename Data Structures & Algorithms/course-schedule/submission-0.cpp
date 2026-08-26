class Solution {
private:
    bool dfs(int node, vector<int>&path, vector<int>&vis, vector<vector<int>>&adj){
        vis[node] = 1;
        path[node] = 1;

        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, path, vis, adj)) return true;
            }else if(path[adjNode] == 1){
                return true; // cycle detected
            }
        }
        path[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() < 1) return true;
        int m = prerequisites[0].size();
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<numCourses;i++){
            // if cycle detected --> not possible to finish all courses
            if(dfs(i, path, vis, adj)) return false;
        }
        return true;
    }
};