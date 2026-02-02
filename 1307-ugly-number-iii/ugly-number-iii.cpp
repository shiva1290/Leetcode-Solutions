class Solution {
public:
 

    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = min(a, min(b, c));
        long long high = 1LL * n * low;

        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long cnt = mid / a + mid / b + mid / c - mid / ab - mid / ac -
                            mid / bc + mid / abc;

            if (cnt < n)
                low = mid + 1;
            else
                high = mid;
        }

        return (int)(low);
    }
};