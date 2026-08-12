class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mpp;
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;

        while(r<n){
            mpp[s[r]]++;

            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};
