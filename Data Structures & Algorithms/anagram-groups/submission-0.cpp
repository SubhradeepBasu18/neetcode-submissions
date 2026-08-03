class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;

        for(string str: strs){
            vector<int>freq(26,0);

            for(char ch: str){
                freq[ch-'a']++;
            }

            string key="";
            for(int cnt: freq){
                key+=to_string(cnt) + "#"; // 1#
            }

            mpp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
