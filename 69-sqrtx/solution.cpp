class Solution {
public:
    int mySqrt(int n) {
        int low = 1;
        int high = n;
        int sqrt;
        if(n==0) return 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long ans =1LL* mid * mid;
            if (ans > (long long)n) {
                high = mid - 1;
            }
            if (ans <= (long long)n) {
                sqrt = mid;
                low = mid + 1;
            }
        }
        return sqrt;
    }
};