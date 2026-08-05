class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0, maxi = 0;

        for(int i=0;i<n-1;i++){

            if(nums[i+1]-nums[i] == 1) cnt++;
            else if(nums[i+1]-nums[i] == 0) continue;
            else{
                maxi = max(maxi, cnt);
                cnt = 0;
            }
            maxi = max(maxi, cnt);
        }
        return maxi+1;
    }
};
