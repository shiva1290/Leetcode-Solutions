class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {}

    void push(int x) {

        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }

        input.push(x);

        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
    }

    int pop() {
        if (empty())
            return -1;
        int ele = input.top();
        input.pop();
        return ele;
    }

    int peek() {
        if (empty())
            return -1;
        return input.top();
    }

    bool empty() { return (input.size() == 0); };
};