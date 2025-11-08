class Solution {
public:
    int myAtoi(string input) {
         int ans = 0;
        int i = 0;
        int n = input.size();
        bool neg = false;

        while (i < n && input[i] == ' ') {
            i++;
        }
        if (input[i] == '+' || input[i] == '-') {
            neg = (input[i] == '-');
            i++;
        }

        while (i < n && input[i] >= '0' && input[i] <= '9') {
            if (ans > (INT_MAX - (input[i]-'0')) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + (input[i] - '0');
            i++;
        }
        return (neg) ? -ans : ans;
    }
};