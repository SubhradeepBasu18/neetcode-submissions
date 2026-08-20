class Solution {
private:
    void f(int ind, int n, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
        // Base Case
        ans.push_back(temp);

        for(int i=ind;i<n;i++){
            if(i>ind && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            f(i+1, n, nums, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        
        f(0, nums.size(), nums, temp, ans);
        return ans;
    }
};
