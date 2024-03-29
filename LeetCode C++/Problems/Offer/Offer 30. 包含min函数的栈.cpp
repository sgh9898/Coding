class MinStack {
private:
    stack<int> stk;
    stack<int> min_stack;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if (min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
    }

    void pop() {
        if (stk.top() == min_stack.top()) {
            min_stack.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int min() {
        return min_stack.top();
    }
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/
