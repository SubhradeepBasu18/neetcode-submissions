class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int maxi = 0;

        while(left<right){
            int water = min(heights[right],heights[left]) * (right-left);
            maxi = max(maxi, water);
            
            if(heights[right]>heights[left]) left++;
            else right--;
        }
        return maxi;
    }
};
