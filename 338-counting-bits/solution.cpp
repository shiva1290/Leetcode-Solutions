class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            result.push_back(hammingWeight(i));
        }
        return result;
    }
};