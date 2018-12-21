class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int buy_1 = -prices[0], buy_0 = -prices[0];
        int sell_2 = 0, sell_1 = 0, sell_0 = 0;
        for (int i=0; i<prices.size(); i++) {
            buy_0 = max(sell_2 - prices[i], buy_1);
            sell_0 = max(sell_1, buy_1 + prices[i]);
            sell_2  = sell_1; sell_1 = sell_0;
            buy_1 = buy_0;
        }
        return sell_0;
    }
};
