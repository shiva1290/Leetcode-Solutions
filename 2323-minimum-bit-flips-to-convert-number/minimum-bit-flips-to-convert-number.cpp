class Solution {
public:
    int countSetBits(int x) {
        int count = 0;
        while (x) {
            x = x & (x - 1);
            count++;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        return countSetBits(start^goal);
    }
};