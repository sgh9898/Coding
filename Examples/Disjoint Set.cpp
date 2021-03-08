class Solution {
private:
    vector<int> parent;
public:
    // parent of every element is initialized to itself
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // find the root node
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }

    // set i's root node to j's root node
    void merge(int i, int j) {
        parent[find(i)] == find(j);
    }
};
