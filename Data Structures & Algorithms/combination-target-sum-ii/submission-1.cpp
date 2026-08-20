class Solution {
private:
    void f(int ind, int target, int n, vector<int>candidates, vector<int>&temp, vector<vector<int>>&ans){
        // Base Case
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) break;

            temp.push_back(candidates[i]);
            f(i+1, target-candidates[i], n, candidates, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        f(0, target, n, candidates, temp, ans);
        return ans;
    }
};
