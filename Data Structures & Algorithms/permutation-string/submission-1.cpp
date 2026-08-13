class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int l = 0, r = 0;
        int n = s2.size(), m = s1.size();

        for(char ch: s1){
            freq1[ch-'a']++;
        }

        while(r<n){
            freq2[s2[r]-'a']++;

            // maintain a window of size 'm'
            if(r-l+1>m){
                freq2[s2[l]-'a']--;
                l++;
            }

            if(freq1 == freq2) return true;
            r++;
        }
        return false;
    }
};
