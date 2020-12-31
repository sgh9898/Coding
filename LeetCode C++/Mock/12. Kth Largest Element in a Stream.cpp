class KthLargest {
private:
    int cap;
    priority_queue<int, vector<int>, greater<int>> que;

public:
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for (int& num:nums) {
            add(num);
        }
    }

    int add(int val) {
        if (que.size() < cap) {
            que.push();
        } else {
            if (val > que.top()) {
                que.pop();
                que.push(val);
            }
        }
        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
