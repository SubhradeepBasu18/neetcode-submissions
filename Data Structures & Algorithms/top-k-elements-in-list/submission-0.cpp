class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

        for(int x: nums){
            freq[x]++;
        }

        vector<pair<int,int>> numFreq;
        for(auto it: freq){
            numFreq.push_back({it.first, it.second});
        }

        sort(numFreq.begin(), numFreq.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(numFreq[i].first);
        }

        return ans;
    }
};
