class MinStack {
    stack<int> s;
    stack<int> minValue;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (minValue.empty() ||val <= minValue.top()  ) {
            minValue.push(val);
        }
    }

    void pop() {

        if (s.top() == minValue.top()) {
            minValue.pop();
        }
        s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return minValue.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */