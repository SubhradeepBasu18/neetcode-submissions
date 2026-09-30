class Solution {
private:
    vector<int>topoSort(int n, vector<vector<int>>adj, vector<int>exists){
        vector<int>indegree(n, 0);
        queue<int>q;
        vector<int>ans;
        int totalChars = 0;

        for(int i=0;i<n;i++){
            if(!exists[i]) continue;
            totalChars++;
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<n;i++){
            if(exists[i] && indegree[i] == 0) q.push(i); 
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        if(ans.size()!=totalChars) return {};
        return ans;
    }
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>adj(26);
        vector<int>exists(26);

        for(auto word: words){
            for(char ch: word){
                exists[ch-'a'] = 1;
            }
        }

        for(int i=0;i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            bool foundDifference = false;
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    foundDifference = true;
                    break;
                }
            }

            if(!foundDifference && s1.size()>s2.size()) return "";
        }

        vector<int>topoOrder = topoSort(26, adj, exists);
        string ans = "";
        if(topoOrder.empty()) return ans;
        for(auto it: topoOrder){
            ans+=char(it+'a');
        }
        return ans;
    }
};
