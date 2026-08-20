class Solution {
private:
    void f(int ind, int n, vector<int>nums, vector<vector<int>>&ans){
        // Base case
        if(ind == n){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<n;i++){
            swap(nums[i], nums[ind]);
            f(ind+1, n, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;

        f(0, n, nums, ans);
        return ans;
    }
};
