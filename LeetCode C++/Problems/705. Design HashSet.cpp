class MyHashSet {
    vector<ListNode*> ms;
    int n = 1e4;
public:
    MyHashSet() {
        ms = vector<ListNode*>(n);
    }

    void add(int key) {
        int idx = key % n;
        if (ms[idx] == nullptr) ms[idx] = new ListNode(key);
        else {
            ListNode* node = ms[idx];
            if (node->val == key) return;
            while (node->next != nullptr) {
                if (node->next->val == key) return;
                node = node->next;
            }
            node->next = new ListNode(key);
        }
    }

    void remove(int key) {
        int idx = key % n;
        if (ms[idx] == nullptr) return;
        if (ms[idx]->val == key) ms[idx] = ms[idx]->next;
        else {
            ListNode* pre = ms[idx];
            ListNode* node = pre->next;
            while (node != nullptr) {
                if (node->val == key) {
                    pre->next = node->next;
                    return;
                }
                pre = node;
                node = node->next;
            }
        }
    }

    bool contains(int key) {
        int idx = key % n;
        ListNode* node = ms[idx];
        while (node != nullptr) {
            if (node->val == key) return true;
            node = node->next;
        }
        return false;
    }
};
