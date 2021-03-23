/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> flattened;
    vector<int>::iterator iter;

    void FlattenList(const vector<NestedInteger>& source) {
        for (auto &list : source) {
            if (list.isInteger()) {
                flattened.push_back(list.getInteger());
            } else {
                FlattenList(list.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        FlattenList(nestedList);
        iter = flattened.begin();
    }

    int next() {
        return *iter++;
    }

    bool hasNext() {
        return iter != flattened.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
