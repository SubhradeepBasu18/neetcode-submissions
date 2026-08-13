class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxLen = 0, maxF = 0;
        unordered_map<char,int>mpp;

        while(r<n){
            mpp[s[r]]++;
            maxF = max(maxF, mpp[s[r]]);
            int len = r-l+1;

            if(len - maxF > k){
                mpp[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, (r-l+1));
            r++;
        }
        return maxLen;
    }
};
