class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i))
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