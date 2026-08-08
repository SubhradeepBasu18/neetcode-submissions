class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char ch: s){
            if(isalnum(ch)) str+=tolower(ch);
        }

        int l = 0, r = str.size()-1;

        while(l<r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
