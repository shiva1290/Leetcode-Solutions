class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto s : tokens) {
            if (s == "+" || s == "*" || s == "-" ||
                s == "/") {
                if (!st.empty()) {
                    int x = 0;
                    int num = st.top();
                    st.pop();
                    if (!st.empty()) {
                        if (s == "+") {
                            x = num + st.top();
                            st.pop();
                            st.push(x);
                        } else if (s == "*") {
                            x = num * st.top();
                            st.pop();
                            st.push(x);
                        } else if (s == "/") {
                            x = st.top() / num;
                            st.pop();
                            st.push(x);
                        } else if (s == "-") {
                            x = st.top() - num;
                            st.pop();
                            st.push(x);
                        }
                    }
                }
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};