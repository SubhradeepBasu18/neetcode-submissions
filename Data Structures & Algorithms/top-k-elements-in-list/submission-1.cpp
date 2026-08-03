class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Bucket Sort Approach
        unordered_map<int,int> mpp;
        for(auto x: nums){
            mpp[x] = 1 + mpp[x];
        }

        vector<vector<int>> freq(nums.size()+1);
        for(auto it: mpp){
            freq[it.second].push_back(it.first);
        }

        vector<int>ans;
        for(int i=freq.size()-1;i>0;i--){
            for(int x: freq[i]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
