class Solution {
public:
    bool Possible(vector<string>& temp, int row, int col,int n) {
        int r = row;
        int c = col;

        while (c >= 0) {
            if (temp[r][c] == 'Q')
                return false;
            c--;
        }

        r = row;
        c = col;

        while (c >= 0 and r >= 0) {
            if (temp[r][c] == 'Q')
                return false;
            c--;
            r--;
        }

        r = row;
        c = col;

        while (c >= 0 and r < n) {
            if (temp[r][c] == 'Q')
                return false;
            c--;
            r++;
        }

        return true;
    }
    void helper(vector<vector<string>> &res, vector<string> &temp, int n, int col) {
        if (col == n) {
            res.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (Possible(temp, row, col,n)) {
                temp[row][col] = 'Q';
                helper(res, temp, n, col + 1);
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp;
        string s;
        for (int i = 0; i < n; i++) {
            s += '.';
        }

        for (int i = 0; i < n; i++) {
            temp.push_back(s);
        }

        helper(res, temp, n, 0);
        return res;
    }
};