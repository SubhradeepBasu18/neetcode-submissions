class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        int n = nums.size();

        for(int i=0;i<n;i++){

            // Remove elements that are out of current window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // Mainting monotonic order - remove all elements that smaller than the current one
            // dq acts like stack here - insert and remove from back
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            // First window is only valid here
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
