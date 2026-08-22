class Solution {
private:
    void f(int ind, string curr, string digits, unordered_map<int,string>mpp, vector<string>&ans){
        
        // Base Case
        if(ind == digits.size()){
            ans.push_back(curr);
            return;
        }

        int digit = digits[ind] - '0';
        string letters = mpp[digit];

        for(char ch: letters){
            curr+=ch;
            f(ind+1, curr, digits, mpp, ans);
            curr.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        unordered_map<int, std::string> mpp = {
            {0, ""}, 
            {1, ""}, 
            {2, "abc"}, 
            {3, "def"},
            {4, "ghi"}, 
            {5, "jkl"}, 
            {6, "mno"},
            {7, "pqrs"}, 
            {8, "tuv"}, 
            {9, "wxyz"}
        };

        f(0, "", digits, mpp, ans);
        return ans;
    }
};
