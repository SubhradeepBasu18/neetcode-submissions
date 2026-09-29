class Solution {
private:
    void dfs(string node, unordered_map<string, vector<string>>&adj, vector<string>&ans){

        while(!adj[node].empty()){
            string nextNode = adj[node].back();
            adj[node].pop_back();
            dfs(nextNode, adj, ans);
        }

        ans.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>>adj;
        vector<string>ans;

        //create the adjancency list
        for(auto ticket: tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        //sort each destination list in reverse order
        for(auto &[from, dest]: adj){
            sort(dest.rbegin(), dest.rend());
        }

        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
