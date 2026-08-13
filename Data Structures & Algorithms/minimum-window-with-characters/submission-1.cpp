class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size(), m = t.size();
        int cnt = 0, minLen = INT_MAX, sIndex = -1;
        int l = 0, r = 0;
        unordered_map<char,int> hash;

        // Pre-Insert
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(r<n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                // Remove s[l] from hash (shrink window)
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--; // a character got reinserted
                l++;
            }
            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};
