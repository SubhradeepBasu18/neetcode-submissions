class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int product = 1;
        int zeroCount = 0;

        vector<int> res(nums.size(), 0);

        for(int x : nums) {
            if(x != 0)
                product *= x;
            else
                zeroCount++;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(zeroCount > 1) {
                res[i] = 0;
            }
            else if(zeroCount == 1) {
                if(nums[i] == 0)
                    res[i] = product;
                else
                    res[i] = 0;
            }
            else {
                res[i] = product / nums[i];
            }
        }

        return res;
    }
};