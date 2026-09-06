class Solution {
    public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int,int>,int>>q;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j},0});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            grid[r][c] = steps;

            for (int i = 0; i < 4; i++) {
            int nrow = r + dr[i];
            int ncol = c + dc[i];

                if (nrow >= 0 && ncol >= 0 && nrow <m && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == INT_MAX){
                    q.push({{nrow, ncol}, steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
    }
};
