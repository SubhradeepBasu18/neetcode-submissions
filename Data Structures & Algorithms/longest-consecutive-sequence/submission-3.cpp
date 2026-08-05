class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = 0;
        unordered_set<int>st;


        for(int x: nums){
            st.insert(x);
        }

        for(int x: nums){

            if(st.find(x-1) == st.end()){
                
                int cnt = 1, curr = x;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    cnt++;
                }

                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};
