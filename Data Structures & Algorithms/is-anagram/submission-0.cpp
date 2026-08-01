class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return false;

        unordered_map<char,int>mpp;

        for(char x: s){
            mpp[x]++;
        }

        for(char x: t){
            mpp[x]--;
        }

        for(auto [ch, cnt]: mpp){
            if(cnt!=0) return false;
        }

        return true;
    }
};
