class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string res;
        for (char c : s) {
            if (c != ']') {
                st.push(c);
            } else {
                string temp;
                while (!st.empty() && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                reverse(temp.begin(),temp.end());

                st.pop();
                string number;
                while(!st.empty() && isdigit(st.top())){
                    number+=st.top();
                    st.pop();
                }
                reverse(number.begin(),number.end());
                int num=stoi(number);
                string result;
                while (num) {
                    result += temp;
                    num--;

                }
                for(char ch: result){
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};