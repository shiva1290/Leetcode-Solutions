class Solution {
   public:
    bool helper(vector<vector<char> >& board, string word, int i, int j,
                int k) {
        if (k == word.size()) {
            return true;
        }
        if (i<0 || j<0 || i >= board.size() || j >=board[0].size() || board[i][j] == ' ' || word[k]!=board[i][j]) {
            return false;
        }
        char x=board[i][j];
        board[i][j] = ' ';
        bool ans = false;

         ans |=helper(board, word, i + 1, j, k + 1);
         ans |=helper(board, word, i - 1, j, k + 1);
         ans |=helper(board, word, i, j - 1, k + 1);
         ans |=helper(board, word, i, j + 1, k + 1);

        board[i][j] = x;
        return ans;
    }
    bool exist(vector<vector<char> >& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if( helper(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};