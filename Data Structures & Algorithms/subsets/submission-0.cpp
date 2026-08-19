class Solution {
private:
    void f(int ind, int n, vector<int>& nums, vector<int> temp, vector<vector<int>>&ans){

        // Base case
        if(ind>=n){
            ans.push_back(temp);
            return;
        }
        // Pick
        temp.push_back(nums[ind]);
        f(ind+1, n, nums, temp, ans);

        // Not pick
        temp.pop_back();
        f(ind+1, n, nums, temp, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        f(0, n, nums, temp, ans);
        return ans;
    }
};
