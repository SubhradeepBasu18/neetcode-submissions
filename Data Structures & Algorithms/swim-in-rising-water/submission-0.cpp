class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(n, 1e9));

        dist[0][0] = 0;
        // elevation, {row, col}
        pq.push({grid[0][0], {0,0}});

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while(!pq.empty()){
            auto it = pq.top();
            int elevation = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if(row == n-1 && col == n-1) return elevation;

            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                    
                    int newElevation = max(elevation, grid[nrow][ncol]);
                    if(newElevation<dist[nrow][ncol]){
                        dist[nrow][ncol]=newElevation;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }

        }
        return dist[n-1][n-1];
    }
};
