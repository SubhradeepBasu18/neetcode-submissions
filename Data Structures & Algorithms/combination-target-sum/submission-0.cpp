class Solution {
private:
    void f(int ind, int target, int n,vector<int>&temp, vector<int>nums, vector<vector<int>>&ans){
        
        //Base Case
        if(ind == n){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        // Pick
        if(nums[ind]<=target){
            temp.push_back(nums[ind]);
            f(ind, target-nums[ind], n, temp, nums, ans);
            temp.pop_back();
        }

        // Not pick
        f(ind+1, target, n, temp, nums, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = nums.size();

        f(0, target, n, temp, nums, ans);
        return ans;
    }
};
