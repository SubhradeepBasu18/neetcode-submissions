class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size();

        // Check rows
        for(int i=0;i<n;i++){
            unordered_set<char>rows;
            
            for(int j=0;j<n;j++){
                if(board[i][j] == '.') continue;

                if(rows.find(board[i][j])!=rows.end()) return false;

                rows.insert(board[i][j]);
            }
        }
        
        // Check columns
        for(int i=0;i<n;i++){
            unordered_set<char>cols;
            
            for(int j=0;j<n;j++){
                if(board[j][i] == '.') continue;

                if(cols.find(board[j][i])!=cols.end()) return false;

                cols.insert(board[j][i]);
            }
        }

        // For 3x3 boxes
        for(int row = 0; row < 9; row += 3) {

            for(int col = 0; col < 9; col += 3) {

                unordered_set<char> box;

                for(int i = row; i < row + 3; i++) {

                    for(int j = col; j < col + 3; j++) {

                        if(board[i][j] == '.') continue;

                        if(box.find(board[i][j]) != box.end())
                            return false;

                        box.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
