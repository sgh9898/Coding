class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = prices[0], sell = prices[0], profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
                sell = prices[i];
            } else {
                sell = max(sell, prices[i]);
            }
            profit = max(profit, sell - buy);
        }
        return profit;
    }
};
