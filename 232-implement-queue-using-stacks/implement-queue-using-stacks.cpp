class MyQueue {
public:
    MyQueue() {
    }
    stack<int>st;
    stack<int> sec;
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()){
            int node=st.top();
            st.pop();
            sec.push(node);
        }
        int ans=sec.top();
        sec.pop();
        while(!sec.empty()){
            st.push(sec.top());
            sec.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!st.empty()){
            int node=st.top();
            st.pop();
            sec.push(node);
        }
        int ans=sec.top();
        while(!sec.empty()){
            st.push(sec.top());
            sec.pop();
        }
        return ans;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */