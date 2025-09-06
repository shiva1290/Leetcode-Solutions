class Solution {
public:
    bool canWePlace(int row, int col, char check, vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == check) {
                return false;
            }
        }

        for (int c = 0; c < 9; c++) {
            if (board[row][c] == check) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == check) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.')
                    continue;
                for (char check = '1'; check <= '9'; check ++) {
                    if (canWePlace(row, col, check, board)) {
                        board[row][col] = check;
                        if(solve(board)){
                            return true;
                        }
                        board[row][col]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};