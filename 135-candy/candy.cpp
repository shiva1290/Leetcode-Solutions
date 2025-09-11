class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1)
            return n;

        int down = 0;
        int up = 0;
        int peak = 0;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (ratings[i] == ratings[i - 1]) {
                up = down = peak = 0;
                count++;
            } else if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                count += up+1;
            } else {
                down++;
                up = 0;
                count +=1 + down - ((peak>=down) ? 1 : 0);
            }
        }
        return count;
    }
};