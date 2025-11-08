class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        bool sign = true;
        if (dividend <= 0 && divisor > 0)
            sign = false;
        if (divisor < 0 && dividend > 0)
            sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            int counter = 0;
            while (n >= d * (1LL << counter + 1)) {
                counter++;
            }
            ans += (1LL << counter);
            n -= d * (1LL << counter);
        }

        if (ans > INT_MAX && sign)
            return INT_MAX;
        if (ans < INT_MIN && !sign)
            return INT_MIN;

        return (sign) ? ans : -ans;
    }
};