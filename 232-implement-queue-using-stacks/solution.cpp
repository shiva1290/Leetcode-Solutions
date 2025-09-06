

class MyQueue {
stack<int> oneSt;
stack<int> twoSt;
public:
    MyQueue() {}

    void push(int x) { oneSt.push(x); }

    int pop() {
        if (twoSt.empty()) {
            while (!oneSt.empty()) {
                int x = oneSt.top();
                twoSt.push(x);
                oneSt.pop();
            }
        }
        if (twoSt.empty())
            return -1;

        int val = twoSt.top();
        twoSt.pop();
        return val;
    }

    int peek() {
        if (twoSt.empty()) {
            while (!oneSt.empty()) {
                int x = oneSt.top();
                twoSt.push(x);
                oneSt.pop();
            }
        }
        return twoSt.top();
    }

    bool empty() { return (oneSt.empty() && twoSt.empty()); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */