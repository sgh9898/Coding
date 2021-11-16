class Solution {
public:
    int numTrees(int n) {
        int c = 1;
        for (int i = 0; i < n; i++) {
            c = 2*c*(2*i+1)/(i+2);
        }
        return c;
    }
};
