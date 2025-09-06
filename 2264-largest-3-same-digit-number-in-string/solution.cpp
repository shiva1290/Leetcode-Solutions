class Solution {
public:
    string largestGoodInteger(string num) {
        int largest = -1;
        int counter = 1;
        int n = num.size();
        string ans;
        for (int i = 1; i < n; i++) {
            if (num[i] == num[i - 1]) {
                counter++;
                if (counter == 3) {
                    int digit = num[i] - '0';
                    if (digit > largest) {
                        ans = string(3, num[i]);
                        largest = digit;
                    }
                }
            } else
                counter = 1;
        }
        return ans;
    }
};