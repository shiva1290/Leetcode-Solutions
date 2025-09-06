
class Solution {
   public:
    int maxElement(vector<vector<int>>& arr, int col) {
        int n = arr.size();
        int max_val = INT_MIN;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i][col] > max_val) {
                max_val = arr[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> result;

        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = maxElement(mat, mid);

            int top = (row == 0) ? -1 : mat[row - 1][mid];
            int left = (mid == 0) ? -1 : mat[row][mid - 1];
            int right = (mid == m - 1) ? -1 : mat[row][mid + 1];
            int bottom = (row == n - 1) ? -1 : mat[row + 1][mid];

            int ele = mat[row][mid];
            if (ele > top && ele > left && ele > right && ele > bottom) {
                return {row, mid};
            } else if (left > ele) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {0, 0};
    }
};