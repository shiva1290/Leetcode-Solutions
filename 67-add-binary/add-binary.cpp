class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n = a.size();
        int m = b.size();
        int k = max(n, m);
        if (n < m) {
            int j = m - n;
            a.insert(0, j, '0');

        } else {
            int j = n - m;
            b.insert(0, j, '0');
        }
        string ans;
        cout<<a<<" "<<b;
        while (k--) {
            int num1 = a[k] - '0';
            int num2 = b[k] - '0';
            int sum = carry + num1 + num2;
            if (sum == 1) {
                carry = 0;
            }
            if (sum == 3) {
                sum = 1;
                carry = 1;
            } else if (sum == 2) {
                sum = 0;
                carry = 1;
            }
            ans.push_back('0' + sum);
        }
        if (carry == 1)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};