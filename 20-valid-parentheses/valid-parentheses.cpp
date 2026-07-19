class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (auto n : s) {
            if (n == '{' || n == '[' || n == '(')
                st.push(n);
            else if ((n == '}' && (!st.empty() && st.top() == '{')) ||
                     (n == ']' && (!st.empty() && st.top() == '[')) ||
                     (n == ')' && (!st.empty() &&  st.top() == '('))) {
                st.pop();
            }
            else return false;
        }
        return st.empty();
    }
};