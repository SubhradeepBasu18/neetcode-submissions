class Solution {
private:
    void dfs(int r, int c, int n, int m, vector<vector<int>>&ocean, vector<vector<int>>&heights, int dr[], int dc[]){
        ocean[r][c] = 1;

        for(int i=0;i<4;i++){
            int nrow = r+dr[i];
            int ncol = c+dc[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !ocean[nrow][ncol] && heights[r][c]<=heights[nrow][ncol]){
                dfs(nrow, ncol, n, m, ocean, heights, dr, dc);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> pacific(n, vector<int>(m, 0));

        vector<vector<int>> res;

        int dr[] = {-1, 0, +1, 0};
        int dc[] =  {0, +1, 0, -1};

        // For Pacific
        for(int c=0;c<m;c++){
            // first row
            dfs(0, c, n, m, pacific, heights, dr, dc);
            // last row
            dfs(n-1, c, n, m, atlantic, heights, dr, dc);
        }

        // For Atlantic
        for(int r=0;r<n;r++){
            // first col
            dfs(r, 0, n, m, pacific, heights, dr, dc);
            // last col
            dfs(r, m-1, n, m, atlantic, heights, dr, dc);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        
        return res;
    }
};
