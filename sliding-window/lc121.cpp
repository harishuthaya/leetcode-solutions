class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay = 0;
        int sellDay = 1;
        int profit = 0;
        while (sellDay < prices.size()) {
            int currProfit = prices[sellDay] - prices[buyDay];
            if (currProfit < 0) {
                buyDay = sellDay;
                sellDay = buyDay + 1;
            } else {
                profit = max(profit, currProfit);
                sellDay += 1;
            }
        }
        return profit;
    }
};

