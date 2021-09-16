class Solution {
    List<Integer> group = new ArrayList<Integer>();
    List<List<Integer>> ans = new ArrayList<List<Integer>>();

    public List<List<Integer>> combine(int n, int k) {
        backtracking(n, 1, k);
        return ans;
    }

    private void backtracking(int n, int index, int k) {
        // elements not enough
        if (group.size() + (n - index + 1) < k) {
            return;
        }
        // save valid answer
        if (group.size() == k) {
            ans.add(new ArrayList<Integer>(group));
            return;
        }
        for (int i = index; i <= n; i++) {
            group.add(i);
            backtracking(n, i + 1, k);
            group.remove(group.size() - 1);
        }
    }
}
