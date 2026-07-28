class MinStack {
public:
    MinStack() {
    }
    stack<int> st;
    stack<int> mini;
    void push(int value) {
        st.push(value);
        if(mini.empty() || mini.top()>=value){
            mini.push(value);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        int val=st.top();
        st.pop();
        if(!mini.empty() && mini.top()==val){
            mini.pop();
        }
    }
    
    int top() {
        if(!st.empty()) return st.top();
        return -1;
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */