class Solution {
public:
    void Backtracking(int& res, int& sum, vector<int>& coins, int idx, int amount) {
      if (sum == amount) {
        res++;
        return;
      }
      if (sum < amount) {
        for (int i = idx; i < coins.size(); i++) {
          sum += coins[i];
          Backtracking(res, sum, coins, i, amount);
          sum -= coins[i];
        }
      }
    }

    int change(int amount, vector<int>& coins) {
      int res = 0, sum = 0;
      Backtracking(res, sum, coins, 0, amount);
      return res;
    }
};
