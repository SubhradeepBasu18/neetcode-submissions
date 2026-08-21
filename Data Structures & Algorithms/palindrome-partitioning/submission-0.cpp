class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void f(int ind, string s, vector<string>&temp, vector<vector<string>>&ans){
        // Base Case
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i-ind+1));
                f(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        f(0, s, temp, ans);
        return ans;
    }
};
