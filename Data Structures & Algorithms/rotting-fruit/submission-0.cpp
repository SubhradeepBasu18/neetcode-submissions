class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int miniTime = 0, cntFresh = 0, cnt = 0;
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }else if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            miniTime = max(miniTime, t);

            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 1;
                    cnt++;
                }
            }
        }
        return (cntFresh == cnt) ? miniTime : -1;
    }
};
