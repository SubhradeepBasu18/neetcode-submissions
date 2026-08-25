class Solution {
   private:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis, int dr[], int dc[],
             int n, int m) {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = r + dr[i];
            int ncol = c + dc[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid, vis, dr, dc, n, m);
            } 
        
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid, vis, dr, dc, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
