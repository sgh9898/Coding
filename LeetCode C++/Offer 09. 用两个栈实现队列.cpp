class CQueue {
private:
    stack<int> head;
    stack<int> tail;

public:
    CQueue() {

    }

    void appendTail(int value) {
        tail.push(value);
    }

    int deleteHead() {
        if (head.empty()) {
            while (!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }
        if (head.empty()) {
            return -1;
        } else {
            int temp = head.top();
            head.pop();
            return temp;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
