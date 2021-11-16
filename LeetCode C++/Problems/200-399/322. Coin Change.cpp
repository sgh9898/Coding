class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> change(amount+1, INT_MAX);
        change[0] = 0;
        for (size_t i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i + coin > amount || change[i] == INT_MAX)  continue;
                change[i+coin] = min(change[i+coin], change[i] + 1);
            }
        }
        return change[amount] == INT_MAX ? -1 : change[amount];
    }
};
