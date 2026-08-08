class Solution {
public:
    bool isPalindrome(string s) {
        string word = "";
        for(char ch: s){
            if(isalnum(ch)) word+=tolower(ch);
        }

        string revWord = word;
        reverse(revWord.begin(), revWord.end());

        return (revWord == word);
    }
};
