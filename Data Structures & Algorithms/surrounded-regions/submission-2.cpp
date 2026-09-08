class Solution {
   private:
    void dfs(int r, int c, int n, int m, int dr[], int dc[], vector<vector<int>>& vis,
             vector<vector<char>>& board) {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = r + dr[i];
            int ncol = c + dc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, n, m, dr, dc, vis, board);
            }
        }
    }

   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        // for rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) dfs(0, j, n, m, dr, dc, vis, board);

            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) dfs(n - 1, j, n, m, dr, dc, vis, board);
        }

        // for cols
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, n, m, dr, dc, vis, board);

            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) dfs(i, m - 1, n, m, dr, dc, vis, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
