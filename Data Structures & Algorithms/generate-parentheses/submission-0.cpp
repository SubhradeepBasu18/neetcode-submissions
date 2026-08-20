class Solution {
private:
    void f(int open, int close, int n, string curr, vector<string>&ans){
        // Base Case
        if(open == n && close == n){
            ans.push_back(curr);
            curr = "";
            return;
        }

        if(open<n) f(open+1, close, n, curr + "(", ans);
        if(close<open) f(open, close+1, n, curr + ")", ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(0,0,n,"",ans);
        return ans;
    }
};
