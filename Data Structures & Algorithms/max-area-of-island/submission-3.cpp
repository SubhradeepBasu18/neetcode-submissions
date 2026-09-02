class Solution {
   private:
    void dfs(int r, int c, int &cnt, int dr[], int dc[], vector<vector<int>>& vis,
            vector<vector<int>>& grid) {
        vis[r][c] = 1;
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nrow = r + dr[i];
            int ncol = c + dc[i];

            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    dfs(nrow, ncol, cnt, dr, dc, vis, grid);
                }
        }
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxCnt = 0;
        vector<vector<int>> adj;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, cnt, dr, dc, vis, grid);
                    maxCnt = max(maxCnt, cnt);
                }
            }
        }
        return maxCnt;
    }
};
