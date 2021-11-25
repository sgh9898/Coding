class MinStack {
    Stack<Integer> stk;
    Stack<Integer> min_stk;


    /** initialize your data structure here. */
    public MinStack() {
        stk = new Stack<Integer>();
        min_stk = new Stack<Integer>();
    }

    public void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x <= min_stk.peek()) min_stk.push(x);
    }

    public void pop() {
        if (stk.peek().equals(min_stk.peek()))  min_stk.pop();
        stk.pop();
    }

    public int top() {
        return stk.peek();
    }

    public int getMin() {
        return min_stk.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
