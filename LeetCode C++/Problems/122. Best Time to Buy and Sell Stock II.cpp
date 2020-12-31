class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())     return 0;
        int cost = prices[0],profit = 0;

        for (int price:prices) {
            if (price >= cost) {    // update profit
                profit += price-cost;
                cost = price;
            } else {                // sell
                cost = price;
            }
        }
        return profit;
    }
};
