class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> res;

        for(int i=0;i<n;i++){
            unordered_set<int> st;

            for(int j=i+1;j<n;j++){
                int rem = -(nums[i]+nums[j]);

                if(st.find(rem)!=st.end()){
                    vector<int>temp = {nums[i], nums[j], rem};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                }

                st.insert(nums[j]);
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
