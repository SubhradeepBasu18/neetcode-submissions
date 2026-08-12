class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256, -1);
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;

        while(r<n){
            // element seen before
            if(hash[s[r]] != -1){
                l = max(hash[s[r]]+1, l); // move l to 1 step ahead of r
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
