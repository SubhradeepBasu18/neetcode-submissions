class Solution {
   private:
    bool dfs(int row, int col, int ind, string word, vector<vector<char>> board,
             vector<vector<int>>& vis) {
        
        // Base Case
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || vis[row][col] ||
            board[row][col] != word[ind])
            return false;

        if (ind == word.size()-1) return true;

        vis[row][col] = 1;

        bool isFound = dfs(row + 1, col, ind+1, word, board, vis) ||
                    dfs(row - 1, col, ind+1, word, board, vis) ||
                    dfs(row, col + 1, ind+1, word, board, vis) ||
                    dfs(row, col - 1, ind+1, word, board, vis);

        vis[row][col] = 0;

        return isFound;
    }

    bool f(string word, vector<vector<char>> board, vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, word, board, vis)) return true;
            }
        }
        return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        return f(word, board, vis);
    }
};
